#include "QtCore/QJsonObject/qjsonvalue_wrap.h"
#include "QtCore/QJsonObject/qjsonobject_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QJsonValueWrap::constructor;

Napi::Object QJsonValueWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QJsonValue";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("toObject", &QJsonValueWrap::toObject),
                   InstanceMethod("toVariant", &QJsonValueWrap::toVariant),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QJsonValueWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QJsonValue* QJsonValueWrap::getInternalInstance() { return this->instance.data(); }

QJsonValueWrap::QJsonValueWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QJsonValueWrap>(info) {
  Napi::Env env = info.Env();
  if (info.Length() == 1) {
    this->instance =
        QSharedPointer<QJsonValue>(info[0].As<Napi::External<QJsonValue>>().Data());
  } else {
    this->instance = QSharedPointer<QJsonValue>(new QJsonValue());
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

Napi::Value QJsonValueWrap::toObject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(this->instance->isObject()) {
    QJsonObject jsonObject = this->instance->toObject();
    auto variant = QJsonObjectWrap::constructor.New(
      {Napi::External<QJsonObject>::New(env, new QJsonObject(jsonObject))});
    return variant;
  }
  return env.Null();
}
Napi::Value QJsonValueWrap::toVariant(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(!this->instance->isNull()) {
    QVariant variantValue = this->instance->toVariant();
    auto variant = QVariantWrap::constructor.New(
      {Napi::External<QVariant>::New(env, new QVariant(variantValue))});
    return variant;
  }
  return env.Null();
}

