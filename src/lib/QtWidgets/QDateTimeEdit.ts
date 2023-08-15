import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { QAbstractSpinBox, QAbstractSpinBoxSignals } from './QAbstractSpinBox';
import { QCalendarWidget } from './QCalendarWidget';
import { QDate } from '../QtCore/QDate';
import { QDateTime } from '../QtCore/QDateTime';
import { QTime } from '../QtCore/QTime';
import { TimeSpec } from '../QtEnums';
import { NativeElement } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { wrapperCache } from '../core/WrapperCache';

/**

> Creates and controls a widget for editing dates and times with spin box layout.

* **This class is a JS wrapper around Qt's [QDateTimeEdit class](https://doc.qt.io/qt-5/qdatetimeedit.html)**

### Example

```javascript
const { QDateTimeEdit, QDate, QTime } = require("@nodegui/nodegui");

const dateTimeEdit = new QDateTimeEdit();

let date = new QDate();
date.setDate(2020, 1, 1);

let time = new QTime();
time.setHMS(16, 30, 0);

dateTimeEdit.setDate(date);
dateTimeEdit.setTime(time);
```
 */
export class QDateTimeEdit extends QAbstractSpinBox<QDateTimeEditSignals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QDateTimeEdit(parent.native);
        } else {
            native = new addon.QDateTimeEdit();
        }
        super(native);
    }
    setCalendarWidget(calendarWidget: QCalendarWidget): void {
        this.native.setCalendarWidget(calendarWidget.native);
    }
    calendarWidget(): QCalendarWidget | null {
        return wrapperCache.getWrapper(this.native.calendarWidget()) as QCalendarWidget;
    }
    setCalendarPopup(enable: boolean): void {
        this.setProperty('calendarPopup', enable);
    }
    calendarPopup(): boolean {
        return this.property('calendarPopup').toBool();
    }
    setDate(date: QDate): void {
        this.setProperty('date', date.native);
    }
    date(): QDate {
        const date = this.property('date');
        return QDate.fromQVariant(date);
    }
    setDateTime(datetime: QDateTime): void {
        this.setProperty('dateTime', datetime.native);
    }
    dateTime(): QDateTime {
        const datetime = this.property('dateTime');
        return QDateTime.fromQVariant(datetime);
    }
    setDisplayFormat(format: string): void {
        this.setProperty('displayFormat', format);
    }
    displayFormat(): string {
        return this.property('displayFormat').toString();
    }
    setTime(time: QTime): void {
        this.setProperty('time', time.native);
    }
    time(): QTime {
        const time = this.property('time');
        return QTime.fromQVariant(time);
    }
    setTimeSpec(spec: TimeSpec): void {
        this.setProperty('timeSpec', spec);
    }
    timeSpec(): TimeSpec {
        return this.property('timeSpec').toInt();
    }
}
wrapperCache.registerWrapper('QDateTimeEditWrap', QDateTimeEdit);

export interface QDateTimeEditSignals extends QAbstractSpinBoxSignals {
    dateChanged: (date: QDate) => void;
    dateTimeChanged: (datetime: QDateTime) => void;
    timeChanged: (time: QTime) => void;
}
