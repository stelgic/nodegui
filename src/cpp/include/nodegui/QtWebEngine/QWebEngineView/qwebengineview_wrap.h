#pragma once

#include <napi.h>

#include <QPointer>
#include <QtWebEngineQuick/qtwebenginequickglobal.h>

#include "Extras/Export/export.h"
#include "nodegui/QtWidgets/QWidget/qwidget_macro.h"
#include "nwebengineview.hpp"

class DLL_EXPORT QWebEngineViewWrap : public Napi::ObjectWrap<QWebEngineViewWrap> {
  QWIDGET_WRAPPED_METHODS_DECLARATION
 private:
  QPointer<QWebEngineView> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebEngineViewWrap(const Napi::CallbackInfo& info);
  ~QWebEngineViewWrap();
  QWebEngineView* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value settings(const Napi::CallbackInfo& info);
  Napi::Value page(const Napi::CallbackInfo& info);
  Napi::Value reload(const Napi::CallbackInfo& info);
  Napi::Value setHtml(const Napi::CallbackInfo& info);
  Napi::Value setZoomFactor(const Napi::CallbackInfo& info);
};

namespace StaticQWebEngineQuickWrapMethods {
DLL_EXPORT Napi::Value initialize(const Napi::CallbackInfo& info);
}
