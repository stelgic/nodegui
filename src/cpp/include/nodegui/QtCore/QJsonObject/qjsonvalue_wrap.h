#pragma once

#include <napi.h>

#include <QJsonValue>
#include <QSharedPointer>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QJsonValueWrap : public Napi::ObjectWrap<QJsonValueWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QSharedPointer<QJsonValue> instance;
    
 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QJsonValueWrap(const Napi::CallbackInfo& info);
 QJsonValue* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  Napi::Value toObject(const Napi::CallbackInfo& info);
  Napi::Value toVariant(const Napi::CallbackInfo& info);
  // wrapped methods
};

