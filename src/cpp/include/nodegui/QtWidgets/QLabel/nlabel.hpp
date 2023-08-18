#pragma once

#include <QLabel>

#include "Extras/Export/export.h"
#include "QtWidgets/QFrame/qframe_macro.h"
#include "QtWidgets/QWidget/qwidget_macro.h"
#include "core/NodeWidget/nodewidget.h"

class DLL_EXPORT NLabel : public QLabel, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QLabel)
 public:
  using QLabel::QLabel;  // inherit all constructors of QLabel

  virtual void connectSignalsToEventEmitter() {
    QFRAME_SIGNALS
    QObject::connect(this, &QLabel::linkActivated, [=](const QString& link) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call({Napi::String::New(env, "linkActivated"),
                             Napi::String::New(env, link.toStdString())});
    });
    QObject::connect(this, &QLabel::linkHovered, [=](const QString& link) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call({Napi::String::New(env, "linkHovered"),
                             Napi::String::New(env, link.toStdString())});
    });
    QObject::connect(this, &QLabel::mousePressEvent, [=](QMouseEvent *event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
          {Napi::External<QMouseEvent>::New(env, new QMouseEvent(*event))});
      this->emitOnNode.Call({Napi::String::New(env, "mousePressEvent"), instance});
    });
    QObject::connect(this, &QLabel::mouseReleaseEvent, [=](QMouseEvent *event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
          {Napi::External<QMouseEvent>::New(env, new QMouseEvent(*event))});
      this->emitOnNode.Call({Napi::String::New(env, "mouseReleaseEvent"), instance});
    });
    QObject::connect(this, &QLabel::mouseMoveEvent, [=](QMouseEvent *event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
          {Napi::External<QMouseEvent>::New(env, new QMouseEvent(*event))});
      this->emitOnNode.Call({Napi::String::New(env, "mouseMoveEvent"), instance});
    });
    QObject::connect(this, &QLabel::mouseDoubleClickEvent, [=](QMouseEvent *event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
          {Napi::External<QMouseEvent>::New(env, new QMouseEvent(*event))});
      this->emitOnNode.Call({Napi::String::New(env, "mouseDoubleClickEvent"), instance});
    });
  }
};
