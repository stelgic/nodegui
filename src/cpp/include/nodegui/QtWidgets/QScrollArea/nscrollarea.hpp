#pragma once

#include <QScrollArea>

#include "Extras/Export/export.h"
#include "QtWidgets/QAbstractScrollArea/qabstractscrollarea_macro.h"
#include "core/NodeWidget/nodewidget.h"

class DLL_EXPORT NScrollArea : public QScrollArea, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QScrollArea)
 public:
  using QScrollArea::QScrollArea;  // inherit all constructors of QScrollArea

  virtual void connectSignalsToEventEmitter() { 
    QABSTRACTSCROLLAREA_SIGNALS 
    QObject::connect(this, &QScrollArea::resized, [=](QResizeEvent* event) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      auto eventWrap = QResizeEventWrap::constructor.New(
        {Napi::External<QResizeEvent>::New(env, event)}); 
      this->emitOnNode.Call({Napi::String::New(env, "resizeEvent"), eventWrap});
    });
  }

  // By-pass `protected` access and expose it.
  void setViewportMargins(int left, int top, int right, int bottom) {
    QScrollArea::setViewportMargins(left, top, right, bottom);
  }
  QMargins viewportMargins() const { return QScrollArea::viewportMargins(); }

signals:
  void resized(QResizeEvent* event);

protected:
  virtual void resizeEvent(QResizeEvent *event) override 
  {
    emit resized(event);
    QScrollArea::resizeEvent(event);
  }
};
