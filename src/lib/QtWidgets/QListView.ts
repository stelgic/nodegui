import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { NativeElement } from '../core/Component';
import { QAbstractItemView, QAbstractItemViewSignals } from './QAbstractItemView';
import { QSize } from '../QtCore/QSize';
import { AlignmentFlag } from '../..';
import { checkIfNativeElement } from '../utils/helpers';
import { wrapperCache } from '../core/WrapperCache';

/**

> The QListView class provides a list or icon view onto a model.

* **This class is a JS wrapper around Qt's [QListView class](https://doc.qt.io/qt-5/qlistview.html)**

### Example

```javascript
const { QListView } = require("@nodegui/nodegui");

const listview = new QListView();

```
 */
export class QListView<Signals extends QListViewSignals = QListViewSignals> extends QAbstractItemView<Signals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QListView(parent.native);
        } else {
            native = new addon.QListView();
        }
        super(native);
    }
    setBatchSize(batchSize: number): void {
        this.setProperty('batchSize', batchSize);
    }
    batchSize(): number {
        return this.property('batchSize').toInt();
    }
    setFlow(flow: Flow): void {
        this.setProperty('flow', flow);
    }
    flow(): Flow {
        return this.property('flow').toInt();
    }
    setGridSize(size: QSize): void {
        this.setProperty('gridSize', size.native);
    }
    gridSize(): QSize {
        const gridSize = this.property('gridSize');
        return QSize.fromQVariant(gridSize);
    }
    setWrapping(enable: boolean): void {
        this.setProperty('isWrapping', enable);
    }
    isWrapping(): boolean {
        return this.property('isWrapping').toBool();
    }
    setItemAlignment(alignment: AlignmentFlag): void {
        this.setProperty('itemAlignment', alignment);
    }
    itemAlignment(): AlignmentFlag {
        return this.property('itemAlignment').toInt();
    }
    setLayoutMode(mode: LayoutMode): void {
        this.setProperty('layoutMode', mode);
    }
    layoutMode(): LayoutMode {
        return this.property('layoutMode').toInt();
    }
    setModelColumn(column: number): void {
        this.setProperty('modelColumn', column);
    }
    modelColumn(): number {
        return this.property('modelColumn').toInt();
    }
    setMovement(movement: Movement): void {
        this.setProperty('movement', movement);
    }
    movement(): Movement {
        return this.property('movement').toInt();
    }
    setResizeMode(mode: ResizeMode): void {
        this.setProperty('resizeMode', mode);
    }
    resizeMode(): ResizeMode {
        return this.property('resizeMode').toInt();
    }
    setSelectionRectVisible(show: boolean): void {
        this.setProperty('selectionRectVisible', show);
    }
    isSelectionRectVisible(): boolean {
        return this.property('selectionRectVisible').toBool();
    }
    setSpacing(space: number): void {
        this.setProperty('spacing', space);
    }
    spacing(): number {
        return this.property('spacing').toInt();
    }
    setUniformItemSizes(enable: boolean): void {
        this.setProperty('uniformItemSizes', enable);
    }
    uniformItemSizes(): boolean {
        return this.property('uniformItemSizes').toBool();
    }
    setViewMode(mode: ListViewMode): void {
        this.setProperty('viewMode', mode);
    }
    viewMode(): ListViewMode {
        return this.property('viewMode').toInt();
    }
    setWordWrap(on: boolean): void {
        this.setProperty('wordWrap', on);
    }
    wordWrap(): boolean {
        return this.property('wordWrap').toBool();
    }
    clearPropertyFlags(): void {
        this.native.clearPropertyFlags();
    }
    setRowHidden(row: number, hide: boolean): void {
        this.native.setRowHidden(row, hide);
    }
    isRowHidden(row: number): boolean {
        return this.native.isRowHidden(row);
    }
}
wrapperCache.registerWrapper('QListViewWrap', QListView);

export enum Flow {
    LeftToRight,
    TopToBottom,
}

export enum LayoutMode {
    SinglePass,
    Batched,
}

export enum Movement {
    Static,
    Free,
    Snap,
}

export enum ResizeMode {
    Fixed,
    Adjust,
}

export enum ListViewMode {
    ListMode,
    IconMode,
}

export type QListViewSignals = QAbstractItemViewSignals;
