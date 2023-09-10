#pragma once

#include <napi.h>

#include <QShowEvent>

#include "Extras/Export/export.h"
#include "QtGui/QEvent/QEvent/qevent_macro.h"
#include "QtGui/QEvent/QInputEvent/qinputevent_macro.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QShowEventWrap : public Napi::ObjectWrap<QShowEventWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
  QEVENT_WRAPPED_METHODS_DECLARATION

 private:
  QShowEvent* instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QShowEventWrap(const Napi::CallbackInfo& info);
  ~QShowEventWrap();
  QShowEvent* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
};
