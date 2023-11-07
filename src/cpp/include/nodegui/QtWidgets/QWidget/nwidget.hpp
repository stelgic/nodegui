#pragma once
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QWidget>

#include "Extras/Export/export.h"
#include "QtWidgets/QWidget/qwidget_macro.h"
#include "core/NodeWidget/nodewidget.h"
#include "QtGui/QEvent/QKeyEvent/qkeyevent_wrap.h"

class DLL_EXPORT NWidget : public QWidget, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QWidget)
 public:
  using QWidget::QWidget;
  // https://doc.qt.io/qt-5/stylesheet-reference.html
  void paintEvent(QPaintEvent* e) override {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
  }

  virtual void connectSignalsToEventEmitter() { 
    QWIDGET_SIGNALS 
    QObject::connect(this, &NWidget::keyReleased, [=](QKeyEvent* event) {       
      Napi::Env env = this->emitOnNode.Env();                                   
      Napi::HandleScope scope(env);                                             
      auto eventWrap = QKeyEventWrap::constructor.New(                           
        {Napi::External<QKeyEvent>::New(env, event)});                          
      this->emitOnNode.Call(                                                    
        {Napi::String::New(env, "keyRelease"), eventWrap});                 
    });                                                                         
  }

  void _protected_updateMicroFocus(Qt::InputMethodQuery query) {
    updateMicroFocus(query);
  }

signals:
  void keyReleased(QKeyEvent* event);

protected:
  virtual void keyReleaseEvent(QKeyEvent* event) override {
    emit keyReleased(event);
    QWidget::keyReleaseEvent(event);
  }
};
