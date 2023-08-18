#pragma once

#include <QLabel>

#include "Extras/Export/export.h"
#include "QtWidgets/QFrame/qframe_macro.h"
#include "QtWidgets/QWidget/qwidget_macro.h"
#include "QtGui/QEvent/QMouseEvent/qmouseevent_wrap.h"
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
    QObject::connect(this, &NLabel::pressed, [=](QMouseEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
        {Napi::External<QMouseEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "pressed"), instance});
    });
    QObject::connect(this, &NLabel::released, [=](QMouseEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
        {Napi::External<QMouseEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "released"), instance});
    });
    QObject::connect(this, &NLabel::doubleClicked, [=](QMouseEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
        {Napi::External<QMouseEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "doubleClicked"), instance});
    });
  }

signals:
  void pressed(QMouseEvent* event);
  void released(QMouseEvent* event);
  void doubleClicked(QMouseEvent* event);

protected:
  virtual void mousePressEvent(QMouseEvent *event) override 
  {
    emit pressed(event);
    QLabel::mousePressEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) override 
  {
    emit released(event);
    QLabel::mouseReleaseEvent(event);
  }

  virtual void mouseDoubleClickEvent(QMouseEvent *event) override 
  {
    emit doubleClicked(event);
    QLabel::mouseDoubleClickEvent(event);
  }
};
