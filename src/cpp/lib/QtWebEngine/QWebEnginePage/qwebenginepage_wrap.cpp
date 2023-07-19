#include "QtWebEngine/QWebEnginePage/qwebenginepage_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtWebEngine/QWebChannel/qwebchannel_wrap.h"

Napi::FunctionReference QWebEnginePageWrap::constructor;

Napi::Object QWebEnginePageWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebEnginePage";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("setWebChannel", &QWebEnginePageWrap::setWebChannel),
        InstanceMethod("webChannel", &QWebEnginePageWrap::webChannel),
       InstanceMethod("runJavaScript", &QWebEnginePageWrap::runJavaScript),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QWebEnginePageWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  QOBJECT_REGISTER_WRAPPER(QWebEnginePage, QWebEnginePageWrap);
  return exports;
}

QWebEnginePageWrap::QWebEnginePageWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QWebEnginePageWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  if (info[0].IsExternal()) {
    this->instance = info[0].As<Napi::External<QWebEnginePage>>().Data();
  } else {
    Napi::TypeError::New(env, "Incorrect initialization of QWebEnginePageWrap")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QWebEnginePage* QWebEnginePageWrap::getInternalInstance() {
  return this->instance;
}

Napi::Value QWebEnginePageWrap::runJavaScript(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::String napiScript = info[0].As<Napi::String>();
  std::string script = napiScript.Utf8Value();

  this->instance->runJavaScript(QString::fromUtf8(script.c_str()));
  return env.Null();
}

Napi::Value QWebEnginePageWrap::setWebChannel(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object channel = info[0].As<Napi::Object>();
  QWebChannelWrap* channelWrap =
      Napi::ObjectWrap<QWebChannelWrap>::Unwrap(channel);

  this->instance->setWebChannel(channelWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QWebEnginePageWrap::webChannel(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QWebChannel* webChannel = this->instance->webChannel();
  return QWebChannelWrap::constructor.New(
      {Napi::External<QWebChannel>::New(env, webChannel)});
}
