#pragma once

#include <napi.h>
#include "core/NodeWidget/nodewidget.h"

#include <QtWebChannel/QWebChannel>

#include "Extras/Export/export.h"
#include "core/Events/eventwidget.h"
#include "core/Events/eventwidget_macro.h"

class DLL_EXPORT NWebChannel : public QWebChannel, public EventWidget {
  Q_OBJECT
  EVENTWIDGET_IMPLEMENTATIONS(QWebChannel)
 public:
  using QWebChannel::QWebChannel;

  void connectSignalsToEventEmitter() { }
};