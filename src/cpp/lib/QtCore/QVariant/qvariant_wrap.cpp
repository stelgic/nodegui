#include "QtCore/QVariant/qvariant_wrap.h"
#include "QtCore/QVariant/qvariantmap_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QVariantWrap::constructor;

Napi::Object QVariantWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QVariant";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("canConvert", &QVariantWrap::canConvert),
                   InstanceMethod("toString", &QVariantWrap::toString),
                   InstanceMethod("toInt", &QVariantWrap::toInt),
                   InstanceMethod("toDouble", &QVariantWrap::toDouble),
                   InstanceMethod("toBool", &QVariantWrap::toBool),
                   InstanceMethod("toStringList", &QVariantWrap::toStringList),
                   InstanceMethod("toIntList", &QVariantWrap::toIntList),
                   InstanceMethod("toFloatList", &QVariantWrap::toFloatList),
                   InstanceMethod("toMap", &QVariantWrap::toMap),
                   StaticMethod("convertToQVariant",
                                &StaticQVariantWrapMethods::convertToQVariant),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QVariantWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QVariant* QVariantWrap::getInternalInstance() { return this->instance.data(); }

QVariantWrap::QVariantWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QVariantWrap>(info) {
  Napi::Env env = info.Env();
  if (info.Length() == 1) {
    this->instance =
        QSharedPointer<QVariant>(info[0].As<Napi::External<QVariant>>().Data());
  } else {
    this->instance = QSharedPointer<QVariant>(new QVariant());
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

Napi::Value QVariantWrap::canConvert(const Napi::CallbackInfo& info) {
  bool success = false;
  Napi::Env env = info.Env();
  std::string value = info[0].As<Napi::String>().Utf8Value();
  if(value == "boolean")
    success = this->instance->canConvert<bool>();
  else if(value == "int")
    success = this->instance->canConvert<int>();
  else if(value == "uint")
    success = this->instance->canConvert<uint>();
  else if(value == "int64")
    success = this->instance->canConvert<int64_t>();
  else if(value == "uint64")
    success = this->instance->canConvert<uint64_t>();
  else if(value == "float")
    success = this->instance->canConvert<float>();
  else if(value == "double")
    success = this->instance->canConvert<double>();
  else if(value == "string")
    success = this->instance->canConvert<QString>();
  else if(value == "string[]")
    success = this->instance->canConvert<QStringList>();

  return Napi::Value::From(env, success);
}
Napi::Value QVariantWrap::toString(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString value = this->instance->value<QString>();
  return Napi::Value::From(env, value.toStdString());
}
Napi::Value QVariantWrap::toInt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int value = this->instance->value<int>();
  return Napi::Value::From(env, value);
}
Napi::Value QVariantWrap::toDouble(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  double value = this->instance->value<double>();
  return Napi::Value::From(env, value);
}
Napi::Value QVariantWrap::toBool(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  bool value = this->instance->value<bool>();
  return Napi::Value::From(env, value);
}
Napi::Value QVariantWrap::toStringList(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QStringList values = this->instance->toStringList();
  Napi::Array result = Napi::Array::New(env, values.size());
  for (int i = 0; i < values.size(); i++) {
    result[i] = Napi::String::New(env, values[i].toStdString());
  }
  return result;
}
Napi::Value QVariantWrap::toIntList(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariantList values = this->instance->toList();
  Napi::Array result = Napi::Array::New(env, values.size());
  for (int i = 0; i < values.size(); i++) {
    result[i] = Napi::Value::From(env, values[i].toInt());
  }
  return result;
}
Napi::Value QVariantWrap::toFloatList(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariantList values = this->instance->toList();
  Napi::Array result = Napi::Array::New(env, values.size());
  for (int i = 0; i < values.size(); i++) {
    result[i] =  Napi::Value::From(env, values[i].toFloat());
  }
  return result;
}
Napi::Value QVariantWrap::toMap(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariantMap valueMap = this->instance->toMap();
  return QVariantMapWrap::constructor.New(
      {Napi::External<QVariantMap>::New(env, new QVariantMap(valueMap))});
}


Napi::Value StaticQVariantWrapMethods::convertToQVariant(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Value value = info[0];
  QVariant* variant = extrautils::convertToQVariant(env, value);
  // Use the variant from extrautils::convertToQVariant function as is and do
  // not create a copy to prevent memory leak
  auto instance = QVariantWrap::constructor.New(
      {Napi::External<QVariant>::New(env, variant)});
  return instance;
}
