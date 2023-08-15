import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { QLayout, QLayoutSignals } from './QLayout';
import { NativeElement } from '../core/Component';
import { AlignmentFlag } from '../QtEnums';
import { wrapperCache } from '../core/WrapperCache';
import { checkIfNativeElement } from '../utils/helpers';
import { QRect } from '../QtCore/QRect';

/**

> The QGridLayout class lays out widgets in a grid.

* **This class is a JS wrapper around Qt's [QGridLayout](https://doc.qt.io/qt-5/qgridlayout.html)**

### Example

```javascript
const { QGridLayout, QWidget, QLabel } = require("@nodegui/nodegui");

const view = new QWidget();
const layout = new QGridLayout();
view.setLayout(layout);

const label = new QLabel();
label.setText("label1");
const label2 = new QLabel();
label2.setText("label2");

layout.addWidget(label);
layout.addWidget(label2);
```

 */
export class QGridLayout extends QLayout<QGridLayoutSignals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QGridLayout(parent.native);
        } else {
            native = new addon.QGridLayout();
        }
        super(native);
    }
    addLayout(
        layout: QLayout,
        row: number,
        column: number,
        rowSpan = 1,
        columnSpan = 1,
        alignment: AlignmentFlag = 0,
    ): void {
        this.native.addLayout(layout.native, row, column, rowSpan, columnSpan, alignment);
    }

    addWidget(widget: QWidget, row = 0, col = 0, rowSpan = 1, colSpan = 1, alignment: AlignmentFlag = 0): void {
        this.native.addWidget(widget.native, row, col, rowSpan, colSpan, alignment);
    }
    removeWidget(widget: QWidget): void {
        this.native.removeWidget(widget.native);
    }
    columnStretch(column: number): number {
        return this.native.columnStretch(column);
    }
    rowStretch(row: number): number {
        return this.native.rowStretch(row);
    }
    setColumnStretch(column: number, stretch: number): void {
        this.native.setColumnStretch(column, stretch);
    }
    setRowStretch(row: number, stretch: number): void {
        this.native.setRowStretch(row, stretch);
    }
    columnMinimumWidth(column: number): number {
        return this.native.columnMinimumWidth(column);
    }
    rowMinimumHeight(row: number): number {
        return this.native.rowMinimumHeight(row);
    }
    setColumnMinimumWidth(column: number, minSize: number): void {
        this.native.setColumnMinimumWidth(column, minSize);
    }
    setRowMinimumHeight(row: number, minSize: number): void {
        this.native.setRowMinimumHeight(row, minSize);
    }
    horizontalSpacing(): number {
        return this.native.horizontalSpacing();
    }
    verticalSpacing(): number {
        return this.native.verticalSpacing();
    }
    setHorizontalSpacing(spacing: number): void {
        this.native.setHorizontalSpacing(spacing);
    }
    setVerticalSpacing(spacing: number): void {
        this.native.setVerticalSpacing(spacing);
    }
    columnCount(): number {
        return this.native.columnCount();
    }
    rowCount(): number {
        return this.native.rowCount();
    }
    contentsRect(): QRect {
        return new QRect(this.native.contentsRect());
    }
}
wrapperCache.registerWrapper('QGridLayoutWrap', QGridLayout);

export type QGridLayoutSignals = QLayoutSignals;
