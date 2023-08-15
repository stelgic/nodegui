#include "QtCore/QJsonObject/qjsonobject_wrap.h"
#include "QtCore/QJsonObject/qjsonvalue_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QJsonObjectWrap::constructor;

Napi::Object QJsonObjectWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QJsonObject";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("toVariantMap", &QJsonObjectWrap::toVariantMap),
                   InstanceMethod("value", &QJsonObjectWrap::value),
                   InstanceMethod("addStringValue", &QJsonObjectWrap::addStringValue),
                   InstanceMethod("addIntValue", &QJsonObjectWrap::addIntValue),
                   InstanceMethod("addBoolValue", &QJsonObjectWrap::addBoolValue),
                   InstanceMethod("addValue", &QJsonObjectWrap::addValue),
                   StaticMethod("fromVariantMap",
                                &StaticQJsonObjectWrapMethods::fromVariantMap),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QJsonObjectWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QJsonObject* QJsonObjectWrap::getInternalInstance() { return this->instance.data(); }

QJsonObjectWrap::QJsonObjectWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QJsonObjectWrap>(info) {
  Napi::Env env = info.Env();
  if (info.Length() == 1) {
    this->instance =
        QSharedPointer<QJsonObject>(info[0].As<Napi::External<QJsonObject>>().Data());
  } else {
    this->instance = QSharedPointer<QJsonObject>(new QJsonObject());
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

Napi::Value QJsonObjectWrap::toVariantMap(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariantMap variantMap = this->instance->toVariantMap();
  
  // TODO: implement conversion to Map
  return env.Null();
}

Napi::Value QJsonObjectWrap::value(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key(info[0].As<Napi::String>().Utf8Value().c_str());
  QJsonValue jsonValue = this->instance->value(key);
  auto instance = QJsonValueWrap::constructor.New(
      {Napi::External<QJsonValue>::New(env, new QJsonValue(jsonValue))});
  return instance;
}

Napi::Value QJsonObjectWrap::addStringValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key(info[0].As<Napi::String>().Utf8Value().c_str());
  QJsonValue value(info[1].As<Napi::String>().Utf8Value().c_str());
  this->instance->insert(key, value);
  return env.Null();
}

Napi::Value QJsonObjectWrap::addIntValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key(info[0].As<Napi::String>().Utf8Value().c_str());
  QJsonValue value(info[1].ToNumber().Int32Value());
  this->instance->insert(key, value);
  return env.Null();
}

Napi::Value QJsonObjectWrap::addBoolValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key(info[0].As<Napi::String>().Utf8Value().c_str());
  QJsonValue value(info[1].ToBoolean().Value());
  this->instance->insert(key, value);
  return env.Null();
}

Napi::Value QJsonObjectWrap::addValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key(info[0].As<Napi::String>().Utf8Value().c_str());
  Napi::Object valueObject = info[1].As<Napi::Object>();
  QVariantWrap* variantWrap = 
    Napi::ObjectWrap<QVariantWrap>::Unwrap(valueObject);
  QJsonValue value = QJsonValue::fromVariant(*variantWrap->getInternalInstance());
  this->instance->insert(key, value);
  return env.Null();
}

Napi::Value StaticQJsonObjectWrapMethods::fromVariantMap(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  // TODO: implement conversion to Map
  return env.Null();
}