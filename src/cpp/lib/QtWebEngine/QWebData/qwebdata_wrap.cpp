#include "QtWebEngine/QWebData/qwebdata_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"

#include "Extras/Utils/nutils.h"
#include "core/WrapperCache/wrappercache.h"

Napi::FunctionReference QWebDataWrap::constructor;

Napi::Object QWebDataWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebData";
  Napi::Function func = DefineClass(
      env, CLASSNAME, 
      {InstanceMethod("getValue", &QWebDataWrap::getValue),
       InstanceMethod("setValue", &QWebDataWrap::setValue),
       QOBJECT_WRAPPED_METHODS_EXPORT_DEFINE(QWebDataWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  QOBJECT_REGISTER_WRAPPER(QWebData, QWebDataWrap);
  return exports;
}

QWebData* QWebDataWrap::getInternalInstance() { return this->instance; }

QWebDataWrap::~QWebDataWrap() { extrautils::safeDelete(this->instance); }

QWebDataWrap::QWebDataWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QWebDataWrap>(info) {
  Napi::Env env = info.Env();
  size_t argCount = info.Length();
  if (argCount == 1) {
    if (info[0].IsExternal()) {
      this->instance = info[0].As<Napi::External<QWebData>>().Data();
    } else {
      Napi::Object parentObject = info[0].As<Napi::Object>();
      QObjectWrap* parentObjectWrap =
          Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
      this->instance = new QWebData(parentObjectWrap->getInternalInstance());
    }
  } else if (argCount == 0) {
    this->instance = new QWebData();
  } else {
    Napi::TypeError::New(env, "NodeGui: QWebDataWrap: Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureQObject(this->getInternalInstance());
}

Napi::Value QWebDataWrap::getValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Array array = Napi::Array::New(env);
  qint64 len = this->instance->value().length();

  for(qint64 i=0; i < len; ++i) {
    QVariant value = this->instance->value().at(0);
    auto valueWrap = QVariantWrap::constructor.New(
        {Napi::External<QVariant>::New(env, new QVariant(value))});
    array.Set(i, valueWrap);
  }
  return array;
}

Napi::Value QWebDataWrap::setValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariantList values;
  Napi::Array array = info[0].As<Napi::Array>();

  for(uint32_t i=0; i < array.Length(); ++i) {
    Napi::Value value = array.Get(i);
    QVariant* variant = extrautils::convertToQVariant(env, value);
    values.append(*variant);
  }
  this->instance->setValue(values);
  return env.Null();
}
