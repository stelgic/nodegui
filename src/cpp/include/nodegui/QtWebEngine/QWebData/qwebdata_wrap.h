#pragma once

#include <napi.h>
#include <QtCore/QObject>

#include <QPointer>

#include "QtWebEngine/QWebData/QWebData.h"
#include "Extras/Export/export.h"
#include "QtCore/QObject/nobject.hpp"
#include "QtCore/QObject/qobject_macro.h"

class DLL_EXPORT QWebDataWrap : public Napi::ObjectWrap<QWebDataWrap> {
  QOBJECT_WRAPPED_METHODS_DECLARATION
 private:
  QPointer<QWebData> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebDataWrap(const Napi::CallbackInfo& info);
  ~QWebDataWrap();
  QWebData* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  static Napi::Object wrapFunc(Napi::Env env, QObject* qobject);
  // Wrapped methods
  Napi::Value getValue(const Napi::CallbackInfo& info);
  Napi::Value setValue(const Napi::CallbackInfo& info);
};

