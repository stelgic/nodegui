#include "QtWebEngine/QWebEngineView/qwebengineview_wrap.h"

#include "QtWebEngine/QWebEngineSettings/qwebenginesettings_wrap.h"
#include "QtWebEngine/QWebEnginePage/qwebenginepage_wrap.h"

#include <QDebug>
#include <QWidget>

#include "Extras/Utils/nutils.h"
#include "QtWidgets/QWidget/qwidget_wrap.h"

Napi::FunctionReference QWebEngineViewWrap::constructor;

Napi::Object QWebEngineViewWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebEngineView";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("settings", &QWebEngineViewWrap::settings),
                   InstanceMethod("page", &QWebEngineViewWrap::page),
                   InstanceMethod("setHtml", &QWebEngineViewWrap::setHtml),
                   QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(QWebEngineViewWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  QOBJECT_REGISTER_WRAPPER(QWebEngineView, QWebEngineViewWrap);
  return exports;
}

QWebEngineView* QWebEngineViewWrap::getInternalInstance() {
  return this->instance;
}

QWebEngineViewWrap::QWebEngineViewWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QWebEngineViewWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    NodeWidgetWrap* parentWidgetWrap =
        Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(parentObject);
    this->instance =
        new NWebEngineView(parentWidgetWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NWebEngineView();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureQWidget(
      this->getInternalInstance(), true);
}

QWebEngineViewWrap::~QWebEngineViewWrap() {
  extrautils::safeDelete(this->instance);
}

Napi::Value QWebEngineViewWrap::settings(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QWebEngineSettings* settings = this->instance->settings();
  return QWebEngineSettingsWrap::constructor.New(
      {Napi::External<QWebEngineSettings>::New(env, settings)});
}

Napi::Value QWebEngineViewWrap::page(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QWebEnginePage* page = this->instance->page();
  return QWebEnginePageWrap::constructor.New(
      {Napi::External<QWebEnginePage>::New(env, page)});
}

Napi::Value QWebEngineViewWrap::setHtml(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::String napiHtml = info[0].As<Napi::String>();
  std::string html = napiHtml.Utf8Value();

  this->instance->setHtml(QString::fromUtf8(html.c_str()));
  return env.Null();
}
