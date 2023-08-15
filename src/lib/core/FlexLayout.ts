import addon from '../utils/addon';
import { QWidget } from '../QtWidgets/QWidget';
import { QLayout, QLayoutSignals } from '../QtWidgets/QLayout';
import { FlexNode } from './YogaWidget';

export type FlexLayoutSignals = QLayoutSignals;

/**

> Custom layout to help layout child widgets using flex layout.

* **This class is a JS wrapper around custom Qt layout implemented using [Yoga](https://github.com/facebook/yoga)**

A `FlexLayout` can be used to layout all child NodeGui widgets using flex.

### Example

```javascript
const { FlexLayout, QWidget, QLabel } = require("@nodegui/nodegui");

const view = new QWidget();
const layout = new FlexLayout();
view.setLayout(layout);

const label = new QLabel();
label.setText("label1");
const label2 = new QLabel();
label2.setText("label2");

layout.addWidget(label);
layout.addWidget(label2);
```
 */
export class FlexLayout extends QLayout<FlexLayoutSignals> {
    protected flexNode?: FlexNode;

    constructor(parent?: QWidget) {
        let native;
        if (parent) {
            native = new addon.FlexLayout(parent.native);
        } else {
            native = new addon.FlexLayout();
        }
        super(native);
        if (parent) {
            this.setFlexNode(parent.getFlexNode());
        }
    }

    addWidget(childWidget: QWidget, childFlexNode?: FlexNode): void {
        const childYogaNode = childFlexNode || childWidget.getFlexNode();
        if (this.children().includes(childWidget)) {
            this.removeWidget(childWidget, childYogaNode);
        }
        this.native.addWidget(childWidget.native, childYogaNode);
    }

    insertChildBefore(
        childWidget: QWidget,
        beforeChildWidget: QWidget,
        childFlexNode?: FlexNode,
        beforeChildFlexNode?: FlexNode,
    ): void {
        const childYogaNode = childFlexNode || childWidget.getFlexNode();
        if (this.children().includes(childWidget)) {
            this.removeWidget(childWidget, childYogaNode);
        }
        const beforeChildYogaNode = beforeChildFlexNode || beforeChildWidget.getFlexNode();
        this.native.insertChildBefore(childWidget.native, beforeChildYogaNode, childYogaNode);
    }

    removeWidget(childWidget: QWidget, childFlexNode?: FlexNode): void {
        const childYogaNode = childFlexNode || childWidget.getFlexNode();
        this.native.removeWidget(childWidget.native, childYogaNode);
    }

    setFlexNode(flexNode: FlexNode): void {
        this.flexNode = flexNode;
        this.native.setFlexNode(flexNode);
    }

    getChildIndex(childWidget: QWidget): number {
        return this.children().indexOf(childWidget);
    }

    getNextSibling(childWidget: QWidget): QWidget | null {
        const childIndex = this.getChildIndex(childWidget);
        const widgetArr = this.children();
        if (childIndex !== -1) {
            return (widgetArr[childIndex + 1] as QWidget) || null;
        }
        return null;
    }
}
