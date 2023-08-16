#include "Extras/Utils/nutils.h"

#include <QApplication>
#include <QMetaType>
#include <QWidget>
#include <string>

#include "core/Component/component_wrap.h"
#include "core/FlexLayout/flexutils.h"
#include "core/YogaWidget/yogawidget.h"

bool extrautils::isNapiValueInt(Napi::Env& env, Napi::Value& num) {
  return env.Global()
      .Get("Number")
      .ToObject()
      .Get("isInteger")
      .As<Napi::Function>()
      .Call({num})
      .ToBoolean()
      .Value();
}

std::string extrautils::getNapiObjectClassName(Napi::Object& object) {
  return object.Get("constructor")
      .As<Napi::Object>()
      .Get("name")
      .As<Napi::String>()
      .Utf8Value();
}

QVariant* extrautils::convertToQVariant(Napi::Env& env, Napi::Value& value) {
  // Warning: Make sure you delete the QVariant fron this function upon use.
  if (value.IsBoolean()) {
    return new QVariant(value.As<Napi::Boolean>().Value());

  } else if (value.IsNumber()) {
    if (isNapiValueInt(env, value)) {
      return new QVariant(value.As<Napi::Number>().Int32Value());
    } else {
      return new QVariant(value.As<Napi::Number>().DoubleValue());
    }

  } else if (value.IsString()) {
    std::string stringValue = value.As<Napi::String>().Utf8Value();
    return new QVariant(stringValue.c_str());

  } else if (value.IsSymbol()) {
    return new QVariant();

  } else if (value.IsArray() && !value.IsTypedArray()) {
    // Note: This assumes an array of strings.
    QVariantList values;
    uint32_t first = 0;
    Napi::Array array = value.As<Napi::Array>();
    uint32_t len = array.Length();
    
    if (array.Get(first).IsString()) {
      for (uint32_t i = 0; i < len; i++) {
        std::string stringValue = array.Get(i).As<Napi::String>().Utf8Value();
        values.append(QString::fromUtf8(stringValue.c_str()));
      }
      return new QVariant(values);
    }

    if (array.Get(first).IsNumber()) {
      Napi::Value val = array.Get(first);
      if (isNapiValueInt(env, val)) {
        for (uint32_t i = 0; i < len; i++) {
          int value = array.Get(i).ToNumber().Int32Value();
          values.append(value);
        }
      }
      else {
        for (uint32_t i = 0; i < len; i++) {
          double value = array.Get(i).ToNumber().DoubleValue();
          values.append(value);
        }
      }
        return new QVariant(values);
    }
    return new QVariant(values);

  } else if (value.IsArrayBuffer()) {
    // TODO: fix this
    return new QVariant();

  } else if (value.IsTypedArray()) {
    QVariantList values;
    Napi::TypedArray array = value.As<Napi::TypedArray>();
    if (array.TypedArrayType() == napi_int32_array) {
      for (uint32_t i = 0; i < array.ElementLength(); i++) {
        int32_t value = array.Get(i).ToNumber().Int32Value();
        values.append(value);
      }
    } else if (array.TypedArrayType() == napi_bigint64_array) {
      for (uint32_t i = 0; i < array.ElementLength(); i++) {
        Napi::BigInt bigVal = array.Get(i);
        int64_t value = array.Get(i).ToNumber().Int64Value();
        values.append(static_cast<qint64>(value));
      }
    } else if(array.TypedArrayType() == napi_float32_array) {
      for (uint32_t i = 0; i < array.ElementLength(); i++) {
        float value = array.Get(i).ToNumber().FloatValue();
        values.append(value);
      }
    } else if(array.TypedArrayType() == napi_float64_array) {
      for (uint32_t i = 0; i < array.ElementLength(); i++) {
        double value = array.Get(i).ToNumber().DoubleValue();
        values.append(value);
      }
    }
    return new QVariant(values);

  } else if (value.IsObject()) {
    Napi::Object object = value.As<Napi::Object>();
    std::string className = getNapiObjectClassName(object);
    QMetaType type = QMetaType::fromName(className.c_str());
    ComponentWrap* componentWrap =
        Napi::ObjectWrap<ComponentWrap>::Unwrap(object);
    return new QVariant(type, componentWrap->rawData);

  } else if (value.IsFunction()) {
    return new QVariant();

  } else if (value.IsPromise()) {
    return new QVariant();

  } else if (value.IsUndefined()) {
    return new QVariant();

  } else if (value.IsNull()) {
    return new QVariant();

  } else if (value.IsBuffer()) {
    // TODO: fix this
    return new QVariant();

  } else if (value.IsExternal()) {
    QVariant* variant = value.As<Napi::External<QVariant>>().Data();
    return variant;

  } else {
    return new QVariant();
  }
}

void* extrautils::configureComponent(void* component) { return component; }

void* extrautils::configureQObject(QObject* object) {
  return configureComponent(object);
}

void* extrautils::configureQWidget(QWidget* widget, bool isLeafNode) {
  YogaWidget* yogaWidget = dynamic_cast<YogaWidget*>(widget);
  if (yogaWidget) {
    flexutils::configureFlexNode(widget, yogaWidget->getFlexNode(), isLeafNode);
  }
  return configureQObject(widget);
}

uint64_t extrautils::hashPointerTo53bit(const void* input) {
  // Hash the address of the object down to something which will
  // fit into the JS 53bit safe integer space.
  uint64_t address = reinterpret_cast<uint64_t>(input);
  uint64_t top8Bits = address & 0xff00000000000000u;
  uint64_t foldedBits = (top8Bits >> 11) ^ address;

  // Clear the top 8bits which we folded, now shift out the last 3 bits
  // Pointers are aligned on 64bit architectures to at least 8bytes
  // boundaries.
  uint64_t result = (foldedBits & ~0xff00000000000000u) >> 3;
  return result;
}

Napi::FunctionReference NUtilsWrap::constructor;

Napi::Object NUtilsWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "NUtils";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {
                      StaticMethod("isNapiExternal",
                                   &StaticNUtilsWrapMethods::isNapiExternal),
                  });
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NUtilsWrap::NUtilsWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<NUtilsWrap>(info) {}

Napi::Value StaticNUtilsWrapMethods::isNapiExternal(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() > 0 && info[0].IsExternal()) {
    return Napi::Boolean::New(env, true);
  }
  return Napi::Boolean::New(env, false);
}
