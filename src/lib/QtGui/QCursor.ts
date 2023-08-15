import addon from '../utils/addon';
import { Component, NativeElement } from '../core/Component';
import { CursorShape } from '../QtEnums';

/**
 
> The QCursor class provides scalable icons in different modes and states.

* **This class is a JS wrapper around Qt's [QCursor class](https://doc.qt.io/qt-5/qcursor.html)**

### Example

```javascript
const { QCursor } = require("@nodegui/nodegui");

const cursor = new QCursor();
```
 */
export class QCursor extends Component {
    constructor();
    constructor(native: NativeElement);
    constructor(shape: CursorShape);
    constructor(arg?: NativeElement | CursorShape) {
        let native: NativeElement;
        if (arg) {
            native = new addon.QCursor(arg);
        } else {
            native = new addon.QCursor();
        }
        super(native);
    }
    pos(): { x: number; y: number } {
        return this.native.pos();
    }
    setPos(x: number, y: number): void {
        return this.native.setPos(x, y);
    }
}
