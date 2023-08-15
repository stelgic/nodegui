---
id: "qboxlayout"
title: "QBoxLayout"
sidebar_label: "QBoxLayout"
---

> Lines up child widgets horizontally or vertically.

**This class is a JS wrapper around Qt's [QBoxLayout class](https://doc.qt.io/qt-5/qboxlayout.html)**

### Example

```javascript
// This example arranges two calendars horizontally.

const { QBoxLayout, QCalendarWidget } = require("@nodegui/nodegui");

const centralWidget = new QWidget();
const boxLayout = new QBoxLayout(0);

boxLayout.addWidget(new QCalendarWidget());
boxLayout.addWidget(new QCalendarWidget());
centralWidget.setLayout(boxLayout);
```

## Hierarchy

  ↳ [NodeLayout](nodelayout.md)‹[QBoxLayoutSignals](../globals.md#qboxlayoutsignals)›

  ↳ **QBoxLayout**

## Index

### Constructors

* [constructor](qboxlayout.md#constructor)

### Properties

* [childLayouts](qboxlayout.md#childlayouts)
* [native](qboxlayout.md#native)
* [nodeChildren](qboxlayout.md#nodechildren)
* [nodeParent](qboxlayout.md#optional-nodeparent)
* [type](qboxlayout.md#type)

### Methods

* [activate](qboxlayout.md#activate)
* [addEventListener](qboxlayout.md#addeventlistener)
* [addLayout](qboxlayout.md#addlayout)
* [addSpacing](qboxlayout.md#addspacing)
* [addStretch](qboxlayout.md#addstretch)
* [addStrut](qboxlayout.md#addstrut)
* [addWidget](qboxlayout.md#addwidget)
* [count](qboxlayout.md#count)
* [direction](qboxlayout.md#direction)
* [inherits](qboxlayout.md#inherits)
* [insertLayout](qboxlayout.md#insertlayout)
* [insertSpacing](qboxlayout.md#insertspacing)
* [insertStretch](qboxlayout.md#insertstretch)
* [insertWidget](qboxlayout.md#insertwidget)
* [invalidate](qboxlayout.md#invalidate)
* [isEnabled](qboxlayout.md#isenabled)
* [objectName](qboxlayout.md#objectname)
* [property](qboxlayout.md#property)
* [removeEventListener](qboxlayout.md#removeeventlistener)
* [removeWidget](qboxlayout.md#removewidget)
* [setContentsMargins](qboxlayout.md#setcontentsmargins)
* [setDirection](qboxlayout.md#setdirection)
* [setEnabled](qboxlayout.md#setenabled)
* [setNodeParent](qboxlayout.md#setnodeparent)
* [setObjectName](qboxlayout.md#setobjectname)
* [setProperty](qboxlayout.md#setproperty)
* [setSizeConstraint](qboxlayout.md#setsizeconstraint)
* [setSpacing](qboxlayout.md#setspacing)
* [setStretch](qboxlayout.md#setstretch)
* [sizeConstraint](qboxlayout.md#sizeconstraint)
* [spacing](qboxlayout.md#spacing)
* [update](qboxlayout.md#update)

## Constructors

###  constructor

\+ **new QBoxLayout**(`dir`: [Direction](../enums/direction.md)): *[QBoxLayout](qboxlayout.md)*

*Overrides [EventWidget](eventwidget.md).[constructor](eventwidget.md#constructor)*

**Parameters:**

Name | Type |
------ | ------ |
`dir` | [Direction](../enums/direction.md) |

**Returns:** *[QBoxLayout](qboxlayout.md)*

\+ **new QBoxLayout**(`dir`: [Direction](../enums/direction.md), `parent`: [NodeWidget](nodewidget.md)‹any›): *[QBoxLayout](qboxlayout.md)*

*Overrides [EventWidget](eventwidget.md).[constructor](eventwidget.md#constructor)*

**Parameters:**

Name | Type |
------ | ------ |
`dir` | [Direction](../enums/direction.md) |
`parent` | [NodeWidget](nodewidget.md)‹any› |

**Returns:** *[QBoxLayout](qboxlayout.md)*

## Properties

###  childLayouts

• **childLayouts**: *Set‹[NodeLayout](nodelayout.md)‹any››*

___

###  native

• **native**: *[NativeElement](../globals.md#nativeelement)*

*Overrides [Component](component.md).[native](component.md#abstract-native)*

___

###  nodeChildren

• **nodeChildren**: *Set‹[Component](component.md)›*

*Inherited from [Component](component.md).[nodeChildren](component.md#nodechildren)*

___

### `Optional` nodeParent

• **nodeParent**? : *[Component](component.md)*

*Inherited from [Component](component.md).[nodeParent](component.md#optional-nodeparent)*

___

###  type

• **type**: *string* = "layout"

*Inherited from [NodeLayout](nodelayout.md).[type](nodelayout.md#type)*

## Methods

###  activate

▸ **activate**(): *boolean*

*Inherited from [NodeLayout](nodelayout.md).[activate](nodelayout.md#activate)*

**Returns:** *boolean*

___

###  addEventListener

▸ **addEventListener**‹**SignalType**›(`signalType`: SignalType, `callback`: QBoxLayoutSignals[SignalType]): *void*

*Inherited from [EventWidget](eventwidget.md).[addEventListener](eventwidget.md#addeventlistener)*

**Type parameters:**

▪ **SignalType**: *keyof QBoxLayoutSignals*

**Parameters:**

Name | Type | Description |
------ | ------ | ------ |
`signalType` | SignalType | SignalType is a signal from the widgets signals interface. |
`callback` | QBoxLayoutSignals[SignalType] | Corresponding callback for the signal as mentioned in the widget's signal interface |

**Returns:** *void*

void

For example in the case of QPushButton:
```js
const button = new QPushButton();
button.addEventListener('clicked',(checked)=>console.log("clicked"));
// here clicked is a value from QPushButtonSignals interface
```

▸ **addEventListener**(`eventType`: [WidgetEventTypes](../enums/widgeteventtypes.md), `callback`: function): *void*

*Inherited from [EventWidget](eventwidget.md).[addEventListener](eventwidget.md#addeventlistener)*

**Parameters:**

▪ **eventType**: *[WidgetEventTypes](../enums/widgeteventtypes.md)*

▪ **callback**: *function*

For example in the case of QPushButton:
```js
const button = new QPushButton();
button.addEventListener(WidgetEventTypes.HoverEnter,()=>console.log("hovered"));
```

▸ (`event?`: [NativeRawPointer](../globals.md#nativerawpointer)‹"QEvent"›): *void*

**Parameters:**

Name | Type |
------ | ------ |
`event?` | [NativeRawPointer](../globals.md#nativerawpointer)‹"QEvent"› |

**Returns:** *void*

___

###  addLayout

▸ **addLayout**(`layout`: [NodeLayout](nodelayout.md)‹any›, `stretch`: number): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`layout` | [NodeLayout](nodelayout.md)‹any› | - |
`stretch` | number | 0 |

**Returns:** *void*

___

###  addSpacing

▸ **addSpacing**(`size`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`size` | number |

**Returns:** *void*

___

###  addStretch

▸ **addStretch**(`stretch`: number): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`stretch` | number | 0 |

**Returns:** *void*

___

###  addStrut

▸ **addStrut**(`size`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`size` | number |

**Returns:** *void*

___

###  addWidget

▸ **addWidget**(`widget`: [NodeWidget](nodewidget.md)‹any›, `stretch`: number, `alignment`: [AlignmentFlag](../enums/alignmentflag.md)): *void*

*Overrides [NodeLayout](nodelayout.md).[addWidget](nodelayout.md#abstract-addwidget)*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`widget` | [NodeWidget](nodewidget.md)‹any› | - |
`stretch` | number | 0 |
`alignment` | [AlignmentFlag](../enums/alignmentflag.md) | 0 |

**Returns:** *void*

___

###  count

▸ **count**(): *number*

**Returns:** *number*

___

###  direction

▸ **direction**(): *[Direction](../enums/direction.md)*

**Returns:** *[Direction](../enums/direction.md)*

___

###  inherits

▸ **inherits**(`className`: string): *boolean*

*Inherited from [NodeObject](nodeobject.md).[inherits](nodeobject.md#inherits)*

**Parameters:**

Name | Type |
------ | ------ |
`className` | string |

**Returns:** *boolean*

___

###  insertLayout

▸ **insertLayout**(`index`: number, `layout`: [NodeLayout](nodelayout.md)‹any›, `stretch`: number): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`index` | number | - |
`layout` | [NodeLayout](nodelayout.md)‹any› | - |
`stretch` | number | 0 |

**Returns:** *void*

___

###  insertSpacing

▸ **insertSpacing**(`index`: number, `size`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`index` | number |
`size` | number |

**Returns:** *void*

___

###  insertStretch

▸ **insertStretch**(`index`: number, `stretch`: number): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`index` | number | - |
`stretch` | number | 0 |

**Returns:** *void*

___

###  insertWidget

▸ **insertWidget**(`index`: number, `widget`: [NodeWidget](nodewidget.md)‹any›, `stretch`: number): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`index` | number | - |
`widget` | [NodeWidget](nodewidget.md)‹any› | - |
`stretch` | number | 0 |

**Returns:** *void*

___

###  invalidate

▸ **invalidate**(): *void*

*Inherited from [NodeLayout](nodelayout.md).[invalidate](nodelayout.md#invalidate)*

**Returns:** *void*

___

###  isEnabled

▸ **isEnabled**(): *boolean*

*Inherited from [NodeLayout](nodelayout.md).[isEnabled](nodelayout.md#isenabled)*

**Returns:** *boolean*

___

###  objectName

▸ **objectName**(): *string*

*Inherited from [NodeObject](nodeobject.md).[objectName](nodeobject.md#objectname)*

**Returns:** *string*

___

###  property

▸ **property**(`name`: string): *[QVariant](qvariant.md)*

*Inherited from [NodeObject](nodeobject.md).[property](nodeobject.md#property)*

**Parameters:**

Name | Type |
------ | ------ |
`name` | string |

**Returns:** *[QVariant](qvariant.md)*

___

###  removeEventListener

▸ **removeEventListener**‹**SignalType**›(`signalType`: SignalType, `callback`: QBoxLayoutSignals[SignalType]): *void*

*Inherited from [EventWidget](eventwidget.md).[removeEventListener](eventwidget.md#removeeventlistener)*

**Type parameters:**

▪ **SignalType**: *keyof QBoxLayoutSignals*

**Parameters:**

Name | Type |
------ | ------ |
`signalType` | SignalType |
`callback` | QBoxLayoutSignals[SignalType] |

**Returns:** *void*

▸ **removeEventListener**(`eventType`: [WidgetEventTypes](../enums/widgeteventtypes.md), `callback`: function): *void*

*Inherited from [EventWidget](eventwidget.md).[removeEventListener](eventwidget.md#removeeventlistener)*

**Parameters:**

▪ **eventType**: *[WidgetEventTypes](../enums/widgeteventtypes.md)*

▪ **callback**: *function*

▸ (`event?`: [NativeRawPointer](../globals.md#nativerawpointer)‹"QEvent"›): *void*

**Parameters:**

Name | Type |
------ | ------ |
`event?` | [NativeRawPointer](../globals.md#nativerawpointer)‹"QEvent"› |

**Returns:** *void*

___

###  removeWidget

▸ **removeWidget**(`widget`: [NodeWidget](nodewidget.md)‹any›): *void*

*Overrides [NodeLayout](nodelayout.md).[removeWidget](nodelayout.md#abstract-removewidget)*

**Parameters:**

Name | Type |
------ | ------ |
`widget` | [NodeWidget](nodewidget.md)‹any› |

**Returns:** *void*

___

###  setContentsMargins

▸ **setContentsMargins**(`left`: number, `top`: number, `right`: number, `bottom`: number): *void*

*Inherited from [NodeLayout](nodelayout.md).[setContentsMargins](nodelayout.md#setcontentsmargins)*

**Parameters:**

Name | Type |
------ | ------ |
`left` | number |
`top` | number |
`right` | number |
`bottom` | number |

**Returns:** *void*

___

###  setDirection

▸ **setDirection**(`dir`: [Direction](../enums/direction.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`dir` | [Direction](../enums/direction.md) |

**Returns:** *void*

___

###  setEnabled

▸ **setEnabled**(`enable`: boolean): *void*

*Inherited from [NodeLayout](nodelayout.md).[setEnabled](nodelayout.md#setenabled)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setNodeParent

▸ **setNodeParent**(`parent?`: [Component](component.md)): *void*

*Inherited from [Component](component.md).[setNodeParent](component.md#setnodeparent)*

**Parameters:**

Name | Type |
------ | ------ |
`parent?` | [Component](component.md) |

**Returns:** *void*

___

###  setObjectName

▸ **setObjectName**(`objectName`: string): *void*

*Inherited from [NodeObject](nodeobject.md).[setObjectName](nodeobject.md#setobjectname)*

**Parameters:**

Name | Type |
------ | ------ |
`objectName` | string |

**Returns:** *void*

___

###  setProperty

▸ **setProperty**(`name`: string, `value`: [QVariantType](../globals.md#qvarianttype)): *boolean*

*Inherited from [NodeObject](nodeobject.md).[setProperty](nodeobject.md#setproperty)*

**Parameters:**

Name | Type |
------ | ------ |
`name` | string |
`value` | [QVariantType](../globals.md#qvarianttype) |

**Returns:** *boolean*

___

###  setSizeConstraint

▸ **setSizeConstraint**(`constraint`: [SizeConstraint](../enums/sizeconstraint.md)): *void*

*Inherited from [NodeLayout](nodelayout.md).[setSizeConstraint](nodelayout.md#setsizeconstraint)*

**Parameters:**

Name | Type |
------ | ------ |
`constraint` | [SizeConstraint](../enums/sizeconstraint.md) |

**Returns:** *void*

___

###  setSpacing

▸ **setSpacing**(`spacing`: number): *void*

*Inherited from [NodeLayout](nodelayout.md).[setSpacing](nodelayout.md#setspacing)*

**Parameters:**

Name | Type |
------ | ------ |
`spacing` | number |

**Returns:** *void*

___

###  setStretch

▸ **setStretch**(`index`: number, `stretch`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`index` | number |
`stretch` | number |

**Returns:** *void*

___

###  sizeConstraint

▸ **sizeConstraint**(): *[SizeConstraint](../enums/sizeconstraint.md)*

*Inherited from [NodeLayout](nodelayout.md).[sizeConstraint](nodelayout.md#sizeconstraint)*

**Returns:** *[SizeConstraint](../enums/sizeconstraint.md)*

___

###  spacing

▸ **spacing**(): *number*

*Inherited from [NodeLayout](nodelayout.md).[spacing](nodelayout.md#spacing)*

**Returns:** *number*

___

###  update

▸ **update**(): *void*

*Inherited from [NodeLayout](nodelayout.md).[update](nodelayout.md#update)*

**Returns:** *void*
