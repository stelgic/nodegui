import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { NativeElement } from '../core/Component';
import { Orientation, AlignmentFlag } from '../QtEnums';
import { wrapperCache } from '../core/WrapperCache';
import { checkIfNativeElement } from '../utils/helpers';

/**

> Create and control progress bar widgets.

* **This class is a JS wrapper around Qt's [QProgressBar class](https://doc.qt.io/qt-5/qprogressbar.html)**

A `QProgressBar` provides ability to add and manipulate native progress bar widgets.

### Example

```javascript
const { QProgressBar } = require("@nodegui/nodegui");

const progressBar = new QProgressBar();
```
 */
export class QProgressBar extends QWidget<QProgressBarSignals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QProgressBar(parent.native);
        } else {
            native = new addon.QProgressBar();
        }
        super(native);
    }
    setAlignment(alignment: AlignmentFlag): void {
        this.setProperty('alignment', alignment);
    }
    alignment(): AlignmentFlag {
        return this.property('alignment').toInt();
    }
    setFormat(format: string): void {
        this.setProperty('format', format);
    }
    format(): string {
        return this.property('format').toString();
    }
    setInvertedAppearance(invert: boolean): void {
        this.setProperty('invertedAppearance', invert);
    }
    invertedAppearance(): boolean {
        return this.property('invertedAppearance').toBool();
    }
    setMaximum(maximum: number): void {
        this.setProperty('maximum', maximum);
    }
    maximum(): number {
        return this.property('maximum').toInt();
    }
    setMinimum(minimum: number): void {
        this.setProperty('minimum', minimum);
    }
    minimum(): number {
        return this.property('minimum').toInt();
    }
    setOrientation(orientation: Orientation): void {
        this.setProperty('orientation', orientation);
    }
    orientation(): Orientation {
        return this.property('orientation').toInt();
    }
    text(): string {
        return this.property('text').toString();
    }
    setTextDirection(textDirection: QProgressBarDirection): void {
        this.setProperty('textDirection', textDirection);
    }
    textDirection(): QProgressBarDirection {
        return this.property('textDirection').toInt();
    }
    setTextVisible(visible: boolean): void {
        this.setProperty('textVisible', visible);
    }
    isTextVisible(): boolean {
        return this.property('textVisible').toBool();
    }
    setValue(value: number): void {
        this.setProperty('value', value);
    }
    value(): number {
        return this.property('value').toInt();
    }
    resetFormat(): void {
        this.native.resetFormat();
    }
    reset(): void {
        this.native.reset();
    }
    setRange(minimum: number, maximum: number): void {
        this.native.setRange(minimum, maximum);
    }
}
wrapperCache.registerWrapper('QProgressBarWrap', QProgressBar);

export enum QProgressBarDirection {
    TopToBottom,
    BottomToTop,
}

export interface QProgressBarSignals extends QWidgetSignals {
    valueChanged: (value: number) => void;
}
