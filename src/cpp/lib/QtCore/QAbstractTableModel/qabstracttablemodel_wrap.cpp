
#include "QtCore/QAbstractTableModel/qabstracttablemodel_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QAbstractTableModelWrap::constructor;

Napi::Object QAbstractTableModelWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QAbstractTableModel";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("initNodeDispatcher",
                      &QAbstractTableModelWrap::initNodeDispatcher),
       InstanceMethod("hasIndex", &QAbstractTableModelWrap::hasIndex),
       InstanceMethod("createIndex", &QAbstractTableModelWrap::createIndex),
       InstanceMethod("_super_flags", &QAbstractTableModelWrap::_super_flags),
       InstanceMethod("emitDataChanged",
                      &QAbstractTableModelWrap::emitDataChanged),
       InstanceMethod("checkIndex", &QAbstractTableModelWrap::checkIndex),
       InstanceMethod("_super_buddy", &QAbstractTableModelWrap::_super_buddy),
       InstanceMethod("beginInsertColumns",
                      &QAbstractTableModelWrap::beginInsertColumns),
       InstanceMethod("beginInsertRows",
                      &QAbstractTableModelWrap::beginInsertRows),
       InstanceMethod("beginMoveColumns",
                      &QAbstractTableModelWrap::beginMoveColumns),
       InstanceMethod("beginMoveRows", &QAbstractTableModelWrap::beginMoveRows),
       InstanceMethod("beginRemoveColumns",
                      &QAbstractTableModelWrap::beginRemoveColumns),
       InstanceMethod("beginRemoveRows",
                      &QAbstractTableModelWrap::beginRemoveRows),
       InstanceMethod("beginResetModel",
                      &QAbstractTableModelWrap::beginResetModel),
       InstanceMethod("endResetModel", &QAbstractTableModelWrap::endResetModel),
       InstanceMethod("endInsertColumns",
                      &QAbstractTableModelWrap::endInsertColumns),
       InstanceMethod("endInsertRows", &QAbstractTableModelWrap::endInsertRows),
       InstanceMethod("endMoveColumns",
                      &QAbstractTableModelWrap::endMoveColumns),
       InstanceMethod("endMoveRows", &QAbstractTableModelWrap::endMoveRows),
       InstanceMethod("endRemoveColumns",
                      &QAbstractTableModelWrap::endRemoveColumns),
       InstanceMethod("endRemoveRows", &QAbstractTableModelWrap::endRemoveRows),
       InstanceMethod("setMaxRows", &QAbstractTableModelWrap::setMaxRows),
       InstanceMethod("setDisplayNumRows", &QAbstractTableModelWrap::setDisplayNumRows),
       InstanceMethod("maxRows", &QAbstractTableModelWrap::maxRows),
       InstanceMethod("fetchedRows", &QAbstractTableModelWrap::fetchedRows),
       QOBJECT_WRAPPED_METHODS_EXPORT_DEFINE(QAbstractTableModelWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  QOBJECT_REGISTER_WRAPPER(NAbstractTableModel, QAbstractTableModelWrap);
  return exports;
}

NAbstractTableModel* QAbstractTableModelWrap::getInternalInstance() {
  return this->instance;
}
QAbstractTableModelWrap::~QAbstractTableModelWrap() {
  extrautils::safeDelete(this->instance);
}

QAbstractTableModelWrap::QAbstractTableModelWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QAbstractTableModelWrap>(info) {
  Napi::Env env = info.Env();
  size_t argCount = info.Length();
  if (argCount == 0) {
    // --- Construct a new instance
    this->instance = new NAbstractTableModel();
  } else if (argCount == 1) {
    if (info[0].IsExternal()) {
      // --- Wrap a given C++ instance
      this->instance = info[0].As<Napi::External<NAbstractTableModel>>().Data();
    }
  } else {
    Napi::TypeError::New(env,
                         "NodeGui: QAbstractTableModelWrap: Wrong number of "
                         "arguments to constructor")
        .ThrowAsJavaScriptException();
  }
}

Napi::Value QAbstractTableModelWrap::initNodeDispatcher(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->dispatchOnNode =
      Napi::Persistent(info[0].As<Napi::Function>());
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::hasIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int row = info[0].As<Napi::Number>().Int32Value();
  int column = info[1].As<Napi::Number>().Int32Value();
  QModelIndexWrap* modelIndexWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[2].As<Napi::Object>());
  QModelIndex* parentIndex = modelIndexWrap->getInternalInstance();

  auto result = Napi::Value::From(
      env, this->instance->hasIndex(row, column, *parentIndex));
  return result;
}

Napi::Value QAbstractTableModelWrap::createIndex(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int row = info[0].As<Napi::Number>().Int32Value();
  int column = info[1].As<Napi::Number>().Int32Value();

  QModelIndex resultIndex = this->instance->_protected_createIndex(row, column);

  auto resultModelIndexWrap = QModelIndexWrap::constructor.New(
      {Napi::External<QModelIndex>::New(env, new QModelIndex(resultIndex))});
  return resultModelIndexWrap;
}

Napi::Value QAbstractTableModelWrap::_super_flags(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* modelIndexWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* index = modelIndexWrap->getInternalInstance();

  auto result = Napi::Value::From(
      env,
      static_cast<uint>(this->instance->QAbstractItemModel::flags(*index)));
  return result;
}

Napi::Value QAbstractTableModelWrap::emitDataChanged(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* topLeftModelIndexWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* topLeftIndex = topLeftModelIndexWrap->getInternalInstance();

  QModelIndexWrap* bottomRightModelIndexWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[1].As<Napi::Object>());
  QModelIndex* bottomRightIndex =
      bottomRightModelIndexWrap->getInternalInstance();

  Napi::Array rolesNapi = info[2].As<Napi::Array>();
  QVector<int> roles(rolesNapi.Length());
  for (int i = 0; i < rolesNapi.Length(); i++) {
    Napi::Value numberNapi = rolesNapi[i];
    roles.append(numberNapi.As<Napi::Number>().Int32Value());
  }

  emit this->instance->dataChanged(*topLeftIndex, *bottomRightIndex, roles);

  return env.Null();
}

Napi::Value QAbstractTableModelWrap::checkIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* modelIndexWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* index = modelIndexWrap->getInternalInstance();

  auto result = Napi::Value::From(
      env, static_cast<uint>(this->instance->checkIndex(*index)));
  return result;
}

Napi::Value QAbstractTableModelWrap::_super_buddy(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* modelIndexWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* index = modelIndexWrap->getInternalInstance();

  auto resultIndex = this->instance->QAbstractItemModel::buddy(*index);

  auto resultModelIndexWrap = QModelIndexWrap::constructor.New(
      {Napi::External<QModelIndex>::New(env, new QModelIndex(resultIndex))});
  return resultModelIndexWrap;
}

Napi::Value QAbstractTableModelWrap::beginInsertColumns(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* parentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* parent = parentWrap->getInternalInstance();
  int first = info[1].As<Napi::Number>().Int32Value();
  int last = info[2].As<Napi::Number>().Int32Value();
  this->instance->_protected_beginInsertColumns(*parent, first, last);
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::beginInsertRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* parentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* parent = parentWrap->getInternalInstance();
  int first = info[1].As<Napi::Number>().Int32Value();
  int last = info[2].As<Napi::Number>().Int32Value();
  this->instance->_protected_beginInsertRows(*parent, first, last);
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::beginMoveColumns(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* sourceParentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* sourceParent = sourceParentWrap->getInternalInstance();
  int sourceFirst = info[1].As<Napi::Number>().Int32Value();
  int sourceLast = info[2].As<Napi::Number>().Int32Value();
  QModelIndexWrap* destinationParentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[3].As<Napi::Object>());
  QModelIndex* destinationParent = destinationParentWrap->getInternalInstance();
  int destinationChild = info[4].As<Napi::Number>().Int32Value();
  bool result = this->instance->_protected_beginMoveColumns(
      *sourceParent, sourceFirst, sourceLast, *destinationParent,
      destinationChild);
  return Napi::Boolean::New(env, result);
}

Napi::Value QAbstractTableModelWrap::beginMoveRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* sourceParentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* sourceParent = sourceParentWrap->getInternalInstance();
  int sourceFirst = info[1].As<Napi::Number>().Int32Value();
  int sourceLast = info[2].As<Napi::Number>().Int32Value();
  QModelIndexWrap* destinationParentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[3].As<Napi::Object>());
  QModelIndex* destinationParent = destinationParentWrap->getInternalInstance();
  int destinationChild = info[4].As<Napi::Number>().Int32Value();
  bool result = this->instance->_protected_beginMoveRows(
      *sourceParent, sourceFirst, sourceLast, *destinationParent,
      destinationChild);
  return Napi::Boolean::New(env, result);
}

Napi::Value QAbstractTableModelWrap::beginRemoveColumns(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* parentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* parent = parentWrap->getInternalInstance();
  int first = info[1].As<Napi::Number>().Int32Value();
  int last = info[2].As<Napi::Number>().Int32Value();
  this->instance->_protected_beginRemoveColumns(*parent, first, last);
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::beginRemoveRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  QModelIndexWrap* parentWrap =
      Napi::ObjectWrap<QModelIndexWrap>::Unwrap(info[0].As<Napi::Object>());
  QModelIndex* parent = parentWrap->getInternalInstance();
  int first = info[1].As<Napi::Number>().Int32Value();
  int last = info[2].As<Napi::Number>().Int32Value();
  this->instance->_protected_beginRemoveRows(*parent, first, last);
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::beginResetModel(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_beginResetModel();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endInsertColumns(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endInsertColumns();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endInsertRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endInsertRows();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endMoveColumns(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endMoveColumns();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endMoveRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endMoveRows();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endRemoveColumns(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endRemoveColumns();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endRemoveRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endRemoveRows();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::endResetModel(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->instance->_protected_endResetModel();
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::setMaxRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int maxRows = info[0].As<Napi::Number>().Int32Value();
  this->instance->setMaxRows(maxRows);
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::setDisplayNumRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int displayRows = info[0].As<Napi::Number>().Int32Value();
  this->instance->setDisplayNumRows(displayRows);
  return env.Null();
}

Napi::Value QAbstractTableModelWrap::maxRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int rows = this->instance->maxRows();
  return Napi::Number::New(env, rows);
}

Napi::Value QAbstractTableModelWrap::fetchedRows(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int rows = this->instance->fetchedRows();
  return Napi::Number::New(env, rows);
}
