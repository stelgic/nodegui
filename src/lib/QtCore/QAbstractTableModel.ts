import addon from '../utils/addon';
import { QObject, QObjectSignals } from '../QtCore/QObject';
import { QModelIndex } from './QModelIndex';
import { QVariant } from './QVariant';
import { ItemDataRole, ItemFlag, Orientation } from '../QtEnums';

export type QAbstractItemSignals = QObjectSignals;

export class QAbstractTableModel extends QObject<any> {
    constructor() {
        super(new addon.QAbstractTableModel());
        const dispatcher = (methodName: string, ...args: any[]): any => {
            switch (methodName) {
                case 'index':
                    try {
                        return this.index(args[0], args[1], new QModelIndex(args[2])).native;
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'index':`);
                        console.log(e);
                    }
                    return new QModelIndex().native;

                case 'parent':
                    try {
                        return this.parentModelIndex(new QModelIndex(args[0])).native;
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'parentModelIndex':`);
                        console.log(e);
                    }
                    return new QModelIndex().native;

                case 'rowCount':
                    try {
                        return this.rowCount(new QModelIndex(args[0]));
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'rowCount':`);
                        console.log(e);
                    }
                    return 0;

                case 'columnCount':
                    try {
                        return this.columnCount(new QModelIndex(args[0]));
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'columnCount':`);
                        console.log(e);
                    }
                    return 0;

                case 'data':
                    try {
                        return this.data(new QModelIndex(args[0]), args[1]).native;
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'data':`);
                        console.log(e);
                    }
                    return new QVariant().native;

                case 'flags':
                    try {
                        return this.flags(new QModelIndex(args[0]));
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'flags':`);
                        console.log(e);
                    }
                    return ItemFlag.NoItemFlags;

                case 'headerData':
                    try {
                        return this.headerData(args[0], args[1], args[2]).native;
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'headerData':`);
                        console.log(e);
                    }
                    return new QVariant().native;

                case 'setData':
                    try {
                        return this.setData(new QModelIndex(args[0]), new QVariant(args[1]), args[2]);
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'setData':`);
                        console.log(e);
                    }
                    return false;

                case 'buddy':
                    try {
                        return this.buddy(new QModelIndex(args[0])).native;
                    } catch (e) {
                        console.log(`An exception was thrown while dispatching to method 'buddy':`);
                        console.log(e);
                    }
                    return new QModelIndex().native;

                default:
                    return null;
            }
        };
        this.native.initNodeDispatcher(dispatcher);
    }

    // *** Public Functions ***

    buddy(child: QModelIndex): QModelIndex {
        return new QModelIndex(this.native._super_buddy(child.native));
    }

    // TODO: virtual bool canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const
    // TODO: virtual bool canFetchMore(const QModelIndex &parent) const

    checkIndex(index: QModelIndex): boolean {
        return this.native.checkIndex(index.native);
    }

    columnCount(parent = new QModelIndex()): number {
        return 0;
    }

    data(index: QModelIndex, role = ItemDataRole.DisplayRole): QVariant {
        return new QVariant();
    }

    // TODO: virtual bool hasChildren(const QModelIndex &parent = QModelIndex()) const

    hasIndex(row: number, column: number, parent = new QModelIndex()): boolean {
        return this.native.hasIndex(row, column, parent.native);
    }

    headerData(section: number, orientation: Orientation, role: number): QVariant {
        return new QVariant();
    }

    // TODO: bool removeColumn(int column, const QModelIndex &parent = QModelIndex())
    // TODO: virtual bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex())
    // TODO: bool removeRow(int row, const QModelIndex &parent = QModelIndex())
    // TODO: virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex())
    // TODO: virtual QHash<int, QByteArray> roleNames() const

    rowCount(parent = new QModelIndex()): number {
        return 0;
    }

    setData(index: QModelIndex, value: QVariant, role = ItemDataRole.EditRole): boolean {
        return false;
    }

    // TODO: virtual bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole)
    // TODO: virtual bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
    // TODO: virtual QModelIndex sibling(int row, int column, const QModelIndex &index) const
    // TODO: virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder)
    // TODO: virtual QSize span(const QModelIndex &index) const
    // TODO: virtual Qt::DropActions supportedDragActions() const
    // TODO: virtual Qt::DropActions supportedDropActions() const

    // *** Public Slots ***

    // TODO: virtual void revert()
    // TODO: virtual bool submit()

    // *** Signals ***

    // Note: Many signals don't need to be explicitly emitted by subclasses and can be safely omitted.

    emitDataChanged(topLeft: QModelIndex, bottomRight: QModelIndex, roles: ItemDataRole[]): void {
        this.native.emitDataChanged(topLeft.native, bottomRight.native, roles);
    }

    // TODO: void headerDataChanged(Qt::Orientation orientation, int first, int last)
    // TODO: void layoutAboutToBeChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint)
    // TODO: void layoutChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint)

    // *** Protected Functions ***
    beginInsertColumns(parent: QModelIndex, first: number, last: number): void {
        this.native.beginInsertColumns(parent.native, first, last);
    }

    beginInsertRows(parent: QModelIndex, first: number, last: number): void {
        this.native.beginInsertRows(parent.native, first, last);
    }

    beginMoveColumns(
        sourceParent: QModelIndex,
        sourceFirst: number,
        sourceLast: number,
        destinationParent: QModelIndex,
        destinationChild: number,
    ): boolean {
        return this.native.beginMoveColumns(
            sourceParent.native,
            sourceFirst,
            sourceLast,
            destinationParent.native,
            destinationChild,
        );
    }

    beginMoveRows(
        sourceParent: QModelIndex,
        sourceFirst: number,
        sourceLast: number,
        destinationParent: QModelIndex,
        destinationChild: number,
    ): boolean {
        return this.native.beginMoveRows(
            sourceParent.native,
            sourceFirst,
            sourceLast,
            destinationParent.native,
            destinationChild,
        );
    }

    beginRemoveColumns(parent: QModelIndex, first: number, last: number): void {
        this.native.beginRemoveColumns(parent.native, first, last);
    }

    beginRemoveRows(parent: QModelIndex, first: number, last: number): void {
        this.native.beginRemoveRows(parent.native, first, last);
    }

    beginResetModel(): void {
        this.native.beginResetModel();
    }
    // TODO: void changePersistentIndex(const QModelIndex &from, const QModelIndex &to)
    // TODO: void changePersistentIndexList(const QModelIndexList &from, const QModelIndexList &to)

    createIndex(row: number, column: number): QModelIndex {
        const result = this.native.createIndex(row, column);
        return new QModelIndex(result);
    }

    // TODO: QModelIndex createIndex(int row, int column, quintptr id) const

    endInsertColumns(): void {
        this.native.endInsertColumns();
    }

    endInsertRows(): void {
        this.native.endInsertRows();
    }

    endMoveColumns(): void {
        this.native.endMoveColumns();
    }

    endMoveRows(): void {
        this.native.endMoveRows();
    }

    endRemoveColumns(): void {
        this.native.endRemoveColumns();
    }

    endRemoveRows(): void {
        this.native.endRemoveRows();
    }

    endResetModel(): void {
        this.native.endResetModel();
    }
    // TODO: QModelIndexList persistentIndexList() const

    index(row: number, column: number, parent = new QModelIndex()): QModelIndex {
        return this.hasIndex(row, column, parent) ? this.createIndex(row, column) : new QModelIndex();
    }

    parentModelIndex(child: QModelIndex): QModelIndex {
        return new QModelIndex();
    }

    sibling(row: number, column: number, index: QModelIndex): QModelIndex {
        return this.index(row, column);
    }

    hasChildren(parent: QModelIndex): boolean {
        if (!parent.isValid()) {
            return this.rowCount(parent) > 0 && this.columnCount(parent) > 0;
        }
        return false;
    }

    flags(index: QModelIndex): ItemFlag {
        let f = this.native._super_flags(index.native);
        if (index.isValid()) {
            f |= ItemFlag.ItemNeverHasChildren;
        }
        return f;
    }

    setMaxRows(rows: number) {
        this.native.setMaxRows(rows);
    }

    setDisplayNumRows(rows: number) {
        this.native.setDisplayNumRows(rows);
    }

    maxRows(): number {
        return this.native.maxRows();
    }

    fetchedRows(): number {
        return this.native.fetchedRows();
    }
}
