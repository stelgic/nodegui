#pragma once
#include <QEvent>
#include <QMainWindow>

#include "Extras/Export/export.h"
#include "QtWidgets/QWidget/qwidget_macro.h"
#include "core/NodeWidget/nodewidget.h"
#include "QtGui/QEvent/QKeyEvent/qkeyevent_wrap.h"

class DLL_EXPORT NMainWindow : public QMainWindow, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QMainWindow)
 public:
  using QMainWindow::QMainWindow;  // inherit all constructors of QMainWindow
  virtual void connectSignalsToEventEmitter() { 
    QWIDGET_SIGNALS 
    QObject::connect(this, &NMainWindow::keyReleased, [=](QKeyEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto instance = QKeyEventWrap::constructor.New(
        {Napi::External<QKeyEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "keyReleased"), instance});
    });
  }

signals:
  void keyReleased(QKeyEvent* event);

protected:
  virtual void keyReleaseEvent(QKeyEvent* event) override {
    emit keyReleased(event);
    QMainWindow::keyReleaseEvent(event);
  }
};
