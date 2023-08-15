#pragma once

#include <napi.h>
#include <nodegui/core/Component/component_macro.h>
#include <QtWebEngineCore/QWebEngineSettings>

class QWebEngineSettingsWrap : public Napi::ObjectWrap<QWebEngineSettingsWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QWebEngineSettings* instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebEngineSettingsWrap(const Napi::CallbackInfo& info);
  QWebEngineSettings* getInternalInstance();
  // Wrapped methods
  Napi::Value setUnknownUrlSchemePolicy(const Napi::CallbackInfo& info);
};
