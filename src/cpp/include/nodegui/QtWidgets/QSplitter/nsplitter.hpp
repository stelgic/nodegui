#pragma once

#include <QSplitter>

#include "Extras/Export/export.h"
#include "QtWidgets/QSplitter/qsplitter_macro.h"
#include "QtGui/QEvent/QMouseEvent/qmouseevent_wrap.h"
#include "core/NodeWidget/nodewidget.h"

class DLL_EXPORT NSplitter : public QSplitter, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QSplitter)
 public:
  using QSplitter::QSplitter;

  virtual void connectSignalsToEventEmitter() { 
    QSPLITTER_SIGNALS 
    QObject::connect(this, &NSplitter::pressed, [=](QMouseEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
        {Napi::External<QMouseEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "pressed"), instance});
    });
    QObject::connect(this, &NSplitter::released, [=](QMouseEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
        {Napi::External<QMouseEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "released"), instance});
    });
    QObject::connect(this, &NSplitter::move, [=](QMouseEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QMouseEventWrap::constructor.New(
        {Napi::External<QMouseEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "move"), instance});
    });
  }

signals:
  void pressed(QMouseEvent* event);
  void released(QMouseEvent* event);
  void move(QMouseEvent* event);

protected:
  virtual void mousePressEvent(QMouseEvent *event) override 
  {
    emit pressed(event);
    QSplitter::mousePressEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent *event) override 
  {
    emit released(event);
    QSplitter::mouseReleaseEvent(event);
  }

  virtual void mouseMoveEvent(QMouseEvent *event) override 
  {
    emit move(event);
    QSplitter::mouseMoveEvent(event);
  }
};
