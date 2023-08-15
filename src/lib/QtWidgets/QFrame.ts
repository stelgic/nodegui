import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { NativeElement } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { QRect } from '../QtCore/QRect';
import { wrapperCache } from '../core/WrapperCache';

/**
 > Create and control frame.

* **This class is a JS wrapper around Qt's [QFrame class](https://doc.qt.io/qt-5/qframe.html)**

The QFrame class is the base class of widgets that can have a frame. It can be used directly for creating simple placeholder frames without any contents.

### Example

```javascript
const { QFrame } = require("@nodegui/nodegui");

const frame = new QFrame();
```
 */
export class QFrame<Signals extends QFrameSignals = QFrameSignals> extends QWidget<Signals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QFrame(parent.native);
        } else {
            native = new addon.QFrame();
        }
        super(native);
    }
    setFrameRect(r: QRect): void {
        this.setProperty('frameRect', r.native);
    }
    frameRect(): QRect {
        return QRect.fromQVariant(this.property('frameRect'));
    }
    setFrameShadow(type: Shadow): void {
        this.setProperty('frameShadow', type);
    }
    frameShadow(): Shadow {
        return this.property('frameShadow').toInt();
    }
    setFrameShape(type: Shape): void {
        this.setProperty('frameShape', type);
    }
    frameShape(): Shape {
        return this.property('frameShape').toInt();
    }
    frameWidth(): number {
        return this.property('frameWidth').toInt();
    }
    setLineWidth(width: number): void {
        this.setProperty('lineWidth', width);
    }
    lineWidth(): number {
        return this.property('lineWidth').toInt();
    }
    setMidLineWidth(width: number): void {
        this.setProperty('midLineWidth', width);
    }
    midLineWidth(): number {
        return this.property('midLineWidth').toInt();
    }
    setFrameStyle(style: number): void {
        this.native.setFrameStyle(style);
    }
    frameStyle(): number {
        return this.native.frameStyle();
    }
}
wrapperCache.registerWrapper('QFrameWrap', QFrame);

export enum Shadow {
    Plain = 0x0010,
    Raised = 0x0020,
    Sunken = 0x0030,
}

export enum Shape {
    NoFrame = 0,
    Box = 0x0001,
    Panel = 0x0002,
    WinPanel = 0x0003,
    HLine = 0x0004,
    VLine = 0x0005,
    StyledPanel = 0x0006,
}

export type QFrameSignals = QWidgetSignals;
