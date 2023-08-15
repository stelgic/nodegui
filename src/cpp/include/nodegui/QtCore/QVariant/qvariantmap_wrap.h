#pragma once

#include <napi.h>

#include <QSharedPointer>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QVariantMapWrap : public Napi::ObjectWrap<QVariantMapWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  std::shared_ptr<QVariantMap> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QVariantMapWrap(const Napi::CallbackInfo& info);
  QVariantMap* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  Napi::Value isEmpty(const Napi::CallbackInfo& info);
  Napi::Value size(const Napi::CallbackInfo& info);
  Napi::Value find(const Napi::CallbackInfo& info);
  Napi::Value insert(const Napi::CallbackInfo& info);
  Napi::Value erase(const Napi::CallbackInfo& info);
  Napi::Value count(const Napi::CallbackInfo& info);
  Napi::Value keys(const Napi::CallbackInfo& info);
  Napi::Value values(const Napi::CallbackInfo& info);
  Napi::Value toQVariant(const Napi::CallbackInfo& info);
  // wrapped methods
};
