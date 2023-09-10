#include "QtGui/QEvent/QShowEvent/qshowevent_wrap.h"

#include <QString>

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QShowEventWrap::constructor;

Napi::Object QShowEventWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QShowEvent";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QShowEventWrap)
        QEVENT_WRAPPED_METHODS_EXPORT_DEFINE(QShowEventWrap)
        QINPUTEVENT_WRAPPED_METHODS_EXPORT_DEFINE(QShowEventWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QShowEvent* QShowEventWrap::getInternalInstance() { return this->instance; }

QShowEventWrap::QShowEventWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QShowEventWrap>(info) {
  Napi::Env env = info.Env();
  if (info.Length() == 1) {
    Napi::External<QShowEvent> eventObject =
        info[0].As<Napi::External<QShowEvent>>();
    this->instance = static_cast<QShowEvent*>(eventObject.Data());
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QShowEventWrap::~QShowEventWrap() {
  // Do not destroy instance here. It will be done by Qt Event loop.
}
