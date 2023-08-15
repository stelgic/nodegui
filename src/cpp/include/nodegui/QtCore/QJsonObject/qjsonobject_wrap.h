#pragma once

#include <napi.h>

#include <QJsonObject>
#include <QSharedPointer>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QJsonObjectWrap : public Napi::ObjectWrap<QJsonObjectWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QSharedPointer<QJsonObject> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QJsonObjectWrap(const Napi::CallbackInfo& info);
  QJsonObject* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  Napi::Value toVariantMap(const Napi::CallbackInfo& info);
  Napi::Value value(const Napi::CallbackInfo& info);
  Napi::Value addStringValue(const Napi::CallbackInfo& info);
  Napi::Value addIntValue(const Napi::CallbackInfo& info);
  Napi::Value addBoolValue(const Napi::CallbackInfo& info);
  Napi::Value addValue(const Napi::CallbackInfo& info);
  // wrapped methods
};

namespace StaticQJsonObjectWrapMethods {
DLL_EXPORT Napi::Value fromVariantMap(const Napi::CallbackInfo& info);
}  // namespace StaticQJsonObjectWrapMethods
