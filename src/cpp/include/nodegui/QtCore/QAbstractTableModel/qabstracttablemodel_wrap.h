#pragma once

#include <napi.h>

#include <QPointer>

#include "Extras/Export/export.h"
#include "QtCore/QObject/qobject_macro.h"
#include "nabstracttablemodel.hpp"

class DLL_EXPORT QAbstractTableModelWrap
    : public Napi::ObjectWrap<QAbstractTableModelWrap> {
  QOBJECT_WRAPPED_METHODS_DECLARATION

 private:
  QPointer<NAbstractTableModel> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QAbstractTableModelWrap(const Napi::CallbackInfo& info);
  ~QAbstractTableModelWrap();
  NAbstractTableModel* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value initNodeDispatcher(const Napi::CallbackInfo& info);

  Napi::Value hasIndex(const Napi::CallbackInfo& info);
  Napi::Value createIndex(const Napi::CallbackInfo& info);
  Napi::Value _super_flags(const Napi::CallbackInfo& info);
  Napi::Value emitDataChanged(const Napi::CallbackInfo& info);
  Napi::Value checkIndex(const Napi::CallbackInfo& info);
  Napi::Value _super_buddy(const Napi::CallbackInfo& info);
  Napi::Value beginInsertColumns(const Napi::CallbackInfo& info);
  Napi::Value beginInsertRows(const Napi::CallbackInfo& info);
  Napi::Value beginMoveColumns(const Napi::CallbackInfo& info);
  Napi::Value beginMoveRows(const Napi::CallbackInfo& info);
  Napi::Value beginRemoveColumns(const Napi::CallbackInfo& info);
  Napi::Value beginRemoveRows(const Napi::CallbackInfo& info);
  Napi::Value beginResetModel(const Napi::CallbackInfo& info);
  Napi::Value endResetModel(const Napi::CallbackInfo& info);
  Napi::Value endInsertColumns(const Napi::CallbackInfo& info);
  Napi::Value endInsertRows(const Napi::CallbackInfo& info);
  Napi::Value endMoveColumns(const Napi::CallbackInfo& info);
  Napi::Value endMoveRows(const Napi::CallbackInfo& info);
  Napi::Value endRemoveColumns(const Napi::CallbackInfo& info);
  Napi::Value endRemoveRows(const Napi::CallbackInfo& info);
  Napi::Value setMaxRows(const Napi::CallbackInfo& info);
  Napi::Value setDisplayNumRows(const Napi::CallbackInfo& info);
  Napi::Value maxRows(const Napi::CallbackInfo& info);
  Napi::Value fetchedRows(const Napi::CallbackInfo& info);
};
