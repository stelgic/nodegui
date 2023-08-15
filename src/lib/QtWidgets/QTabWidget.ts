import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { NativeElement } from '../core/Component';
import { QIcon } from '../QtGui/QIcon';
import { TabPosition } from '../QtEnums';
import { wrapperCache } from '../core/WrapperCache';
import { checkIfNativeElement } from '../utils/helpers';

/**

> Create and control a stack of tabbed widgets.

* **This class is a JS wrapper around Qt's [QTabWidget class](https://doc.qt.io/qt-5/qtabwidget.html)**

A 'QTabWidget' provides a tab bar and a "page area" that is used to display pages related to each tab.

### Example

```javascript
// This example creates two tabs, each holding a separate calendar.
const { QTabWidget, QCalendarWidget, QIcon } = require("@nodegui/nodegui");

const tabWidget = new QTabWidget();

tabWidget.addTab(new QCalendarWidget(), new QIcon(), 'Tab 1');
tabWidget.addTab(new QCalendarWidget(), new QIcon(), 'Tab 2');
```
 */
export class QTabWidget extends QWidget<QTabWidgetSignals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QTabWidget(parent.native);
        } else {
            native = new addon.QTabWidget();
        }
        super(native);
    }

    addTab(page: QWidget, icon: QIcon, label: string): number {
        const index = this.native.addTab(page.native, icon.native, label);
        page.setFlexNodeSizeControlled(true);
        return index;
    }

    insertTab(index: number, page: QWidget, icon: QIcon, label: string): number {
        const newIndex = this.native.insertTab(index, page.native, icon.native, label);
        return newIndex;
    }

    indexOf(widget: QWidget): number {
        return this.native.indexOf(widget.native);
    }

    setTabPosition(tabPosition: TabPosition): void {
        this.native.setTabPosition(tabPosition);
    }

    setTabText(tabIndex: number, tabText: string): void {
        this.native.setTabText(tabIndex, tabText);
    }

    setTabIcon(tabIndex: number, icon: QIcon): void {
        this.native.setTabIcon(tabIndex, icon.native);
    }

    setCurrentIndex(index: number): void {
        this.native.setCurrentIndex(index);
    }

    currentIndex(): number {
        return this.native.currentIndex();
    }

    removeTab(index: number): void {
        this.native.removeTab(index);
        const toRemove = this.widget(index);
        toRemove.setFlexNodeSizeControlled(false);
    }

    setTabsClosable(closeable: boolean): void {
        this.native.setTabsClosable(closeable);
    }

    widget(index: number): QWidget {
        return wrapperCache.getWrapper(this.native.widget(index)) as QWidget;
    }
}
wrapperCache.registerWrapper('QTabWidgetWrap', QTabWidget);

export interface QTabWidgetSignals extends QWidgetSignals {
    currentChanged: (index: number) => void;
    tabBarClicked: (index: number) => void;
    tabBarDoubleClicked: (index: number) => void;
    tabCloseRequested: (index: number) => void;
}
