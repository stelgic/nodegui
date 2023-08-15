#include "QtCore/QVariant/qvariantmap_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QVariantMapWrap::constructor;

Napi::Object QVariantMapWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QVariantMap";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("isEmpty", &QVariantMapWrap::isEmpty),
                   InstanceMethod("size", &QVariantMapWrap::size),
                   InstanceMethod("find", &QVariantMapWrap::find),
                   InstanceMethod("insert", &QVariantMapWrap::insert),
                   InstanceMethod("erase", &QVariantMapWrap::erase),
                   InstanceMethod("count", &QVariantMapWrap::count),
                   InstanceMethod("keys", &QVariantMapWrap::keys),
                   InstanceMethod("values", &QVariantMapWrap::values),
                   InstanceMethod("toQVariant", &QVariantMapWrap::toQVariant),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QVariantMapWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QVariantMap* QVariantMapWrap::getInternalInstance() { return this->instance.get(); }

QVariantMapWrap::QVariantMapWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QVariantMapWrap>(info) {
  Napi::Env env = info.Env();
  if (info.Length() == 1) {
    this->instance =
        std::shared_ptr<QVariantMap>(info[0].As<Napi::External<QVariantMap>>().Data());
  } else {
    this->instance = std::make_shared<QVariantMap>();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

Napi::Value QVariantMapWrap::isEmpty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  bool value = this->instance->isEmpty();
  return Napi::Value::From(env, value);
}
Napi::Value QVariantMapWrap::size(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int64_t value = static_cast<int64_t>(this->instance->size());
  return Napi::Value::From(env, value);
}
Napi::Value QVariantMapWrap::find(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key = QString::fromUtf8(info[0].As<Napi::String>().Utf8Value().c_str());
  QVariantMap::iterator iter = this->instance->find(key);
  if(iter != this->instance->end()) {
    auto variant = QVariantWrap::constructor.New(
      {Napi::External<QVariant>::New(env, new QVariant(iter.value()))});
    return variant;
  }
  return env.Null();
}
Napi::Value QVariantMapWrap::insert(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key = QString::fromUtf8(info[0].As<Napi::String>().Utf8Value().c_str());
  QVariant* variant = info[1].As<Napi::External<QVariant>>().Data();
  this->instance->insert(key, *variant);
  return env.Null();
}
Napi::Value QVariantMapWrap::erase(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key = QString::fromUtf8(info[0].As<Napi::String>().Utf8Value().c_str());
  QVariantMap::iterator iter = this->instance->find(key);
  if(iter != this->instance->end()) {
    this->instance->erase(iter);
  }
  return env.Null();
}
Napi::Value QVariantMapWrap::count(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QString key = QString::fromUtf8(info[0].As<Napi::String>().Utf8Value().c_str());
  int64_t value = static_cast<int64_t>(this->instance->count(key));
  return Napi::Value::From(env, value);
}
Napi::Value QVariantMapWrap::keys(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QStringList keys = this->instance->keys();
  Napi::Array result = Napi::Array::New(env, keys.size());
  for (int i = 0; i < keys.size(); i++) {
    result[i] = Napi::Value::From(env, keys[i].toUtf8().toStdString());
  }
  return result;
}
Napi::Value QVariantMapWrap::values(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariantList values = this->instance->values();
  Napi::Array result = Napi::Array::New(env, values.size());
  for (int i = 0; i < values.size(); i++) {
    auto variant = QVariantWrap::constructor.New(
      {Napi::External<QVariant>::New(env, new QVariant(values))});
    result[i] = variant;
  }
  return result;
}
Napi::Value QVariantMapWrap::toQVariant(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QVariant values = QVariant::fromValue(*this->instance.get());
  return QVariantWrap::constructor.New(
      {Napi::External<QVariant>::New(env, new QVariant(values))});
}

