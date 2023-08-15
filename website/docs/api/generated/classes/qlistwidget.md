---
id: "qlistwidget"
title: "QListWidget"
sidebar_label: "QListWidget"
---

> Create and control a item-based list.

**This class is a JS wrapper around Qt's [QListWidget class](https://doc.qt.io/qt-5/qlistwidget.html)**

### Example

```javascript
const { QListWidget, QListWidgetItem } = require("@nodegui/nodegui");

const listWidget = new QListWidget();

for (let i = 0; i < 30; i++) {
let listWidgetItem = new QListWidgetItem();
listWidgetItem.setText('listWidgetItem ' + i);
if (i===3) {
listWidgetItem.setCheckState(2);
} else {
listWidgetItem.setCheckState(0);
}
listWidget.addItem(listWidgetItem);
}
```

## Hierarchy

  ↳ [NodeListView](nodelistview.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)›

  ↳ **QListWidget**

## Index

### Constructors

* [constructor](qlistwidget.md#constructor)

### Properties

* [_layout](qlistwidget.md#optional-_layout)
* [_rawInlineStyle](qlistwidget.md#_rawinlinestyle)
* [actions](qlistwidget.md#actions)
* [items](qlistwidget.md#items)
* [native](qlistwidget.md#native)
* [nodeChildren](qlistwidget.md#nodechildren)
* [nodeParent](qlistwidget.md#optional-nodeparent)
* [type](qlistwidget.md#type)
* [viewportWidget](qlistwidget.md#optional-viewportwidget)

### Accessors

* [layout](qlistwidget.md#layout)

### Methods

* [acceptDrops](qlistwidget.md#acceptdrops)
* [activateWindow](qlistwidget.md#activatewindow)
* [addAction](qlistwidget.md#addaction)
* [addEventListener](qlistwidget.md#addeventlistener)
* [addItem](qlistwidget.md#additem)
* [addItems](qlistwidget.md#additems)
* [adjustSize](qlistwidget.md#adjustsize)
* [alternatingRowColors](qlistwidget.md#alternatingrowcolors)
* [autoScrollMargin](qlistwidget.md#autoscrollmargin)
* [batchSize](qlistwidget.md#batchsize)
* [clear](qlistwidget.md#clear)
* [clearFocus](qlistwidget.md#clearfocus)
* [clearPropertyFlags](qlistwidget.md#clearpropertyflags)
* [close](qlistwidget.md#close)
* [closePersistentEditor](qlistwidget.md#closepersistenteditor)
* [count](qlistwidget.md#count)
* [currentIndex](qlistwidget.md#currentindex)
* [currentItem](qlistwidget.md#currentitem)
* [currentRow](qlistwidget.md#currentrow)
* [defaultDropAction](qlistwidget.md#defaultdropaction)
* [dragDropMode](qlistwidget.md#dragdropmode)
* [dragDropOverwriteMode](qlistwidget.md#dragdropoverwritemode)
* [dragEnabled](qlistwidget.md#dragenabled)
* [editItem](qlistwidget.md#edititem)
* [editTriggers](qlistwidget.md#edittriggers)
* [findItems](qlistwidget.md#finditems)
* [flow](qlistwidget.md#flow)
* [font](qlistwidget.md#font)
* [frameRect](qlistwidget.md#framerect)
* [frameShadow](qlistwidget.md#frameshadow)
* [frameShape](qlistwidget.md#frameshape)
* [frameStyle](qlistwidget.md#framestyle)
* [frameWidth](qlistwidget.md#framewidth)
* [geometry](qlistwidget.md#geometry)
* [getFlexNode](qlistwidget.md#getflexnode)
* [gridSize](qlistwidget.md#gridsize)
* [hasAutoScroll](qlistwidget.md#hasautoscroll)
* [hasMouseTracking](qlistwidget.md#hasmousetracking)
* [hide](qlistwidget.md#hide)
* [horizontalScrollMode](qlistwidget.md#horizontalscrollmode)
* [iconSize](qlistwidget.md#iconsize)
* [indexWidget](qlistwidget.md#indexwidget)
* [inherits](qlistwidget.md#inherits)
* [insertItem](qlistwidget.md#insertitem)
* [insertItems](qlistwidget.md#insertitems)
* [isActiveWindow](qlistwidget.md#isactivewindow)
* [isEnabled](qlistwidget.md#isenabled)
* [isPersistentEditorOpen](qlistwidget.md#ispersistenteditoropen)
* [isRowHidden](qlistwidget.md#isrowhidden)
* [isSelectionRectVisible](qlistwidget.md#isselectionrectvisible)
* [isSortingEnabled](qlistwidget.md#issortingenabled)
* [isVisible](qlistwidget.md#isvisible)
* [isWrapping](qlistwidget.md#iswrapping)
* [item](qlistwidget.md#item)
* [itemAlignment](qlistwidget.md#itemalignment)
* [itemAt](qlistwidget.md#itemat)
* [itemWidget](qlistwidget.md#itemwidget)
* [layoutMode](qlistwidget.md#layoutmode)
* [lineWidth](qlistwidget.md#linewidth)
* [lower](qlistwidget.md#lower)
* [mapFromGlobal](qlistwidget.md#mapfromglobal)
* [mapFromParent](qlistwidget.md#mapfromparent)
* [mapToGlobal](qlistwidget.md#maptoglobal)
* [mapToParent](qlistwidget.md#maptoparent)
* [maximumSize](qlistwidget.md#maximumsize)
* [maximumViewportSize](qlistwidget.md#maximumviewportsize)
* [midLineWidth](qlistwidget.md#midlinewidth)
* [minimumSize](qlistwidget.md#minimumsize)
* [modelColumn](qlistwidget.md#modelcolumn)
* [move](qlistwidget.md#move)
* [movement](qlistwidget.md#movement)
* [objectName](qlistwidget.md#objectname)
* [openPersistentEditor](qlistwidget.md#openpersistenteditor)
* [pos](qlistwidget.md#pos)
* [property](qlistwidget.md#property)
* [raise](qlistwidget.md#raise)
* [removeAction](qlistwidget.md#removeaction)
* [removeEventListener](qlistwidget.md#removeeventlistener)
* [removeItemWidget](qlistwidget.md#removeitemwidget)
* [repaint](qlistwidget.md#repaint)
* [repolish](qlistwidget.md#repolish)
* [resetHorizontalScrollMode](qlistwidget.md#resethorizontalscrollmode)
* [resetVerticalScrollMode](qlistwidget.md#resetverticalscrollmode)
* [resize](qlistwidget.md#resize)
* [resizeMode](qlistwidget.md#resizemode)
* [row](qlistwidget.md#row)
* [scrollToBottom](qlistwidget.md#scrolltobottom)
* [scrollToItem](qlistwidget.md#scrolltoitem)
* [scrollToTop](qlistwidget.md#scrolltotop)
* [selectedItems](qlistwidget.md#selecteditems)
* [selectionBehavior](qlistwidget.md#selectionbehavior)
* [selectionMode](qlistwidget.md#selectionmode)
* [setAcceptDrops](qlistwidget.md#setacceptdrops)
* [setAlternatingRowColors](qlistwidget.md#setalternatingrowcolors)
* [setAttribute](qlistwidget.md#setattribute)
* [setAutoScroll](qlistwidget.md#setautoscroll)
* [setAutoScrollMargin](qlistwidget.md#setautoscrollmargin)
* [setBatchSize](qlistwidget.md#setbatchsize)
* [setContextMenuPolicy](qlistwidget.md#setcontextmenupolicy)
* [setCurrentIndex](qlistwidget.md#setcurrentindex)
* [setCurrentItem](qlistwidget.md#setcurrentitem)
* [setCurrentRow](qlistwidget.md#setcurrentrow)
* [setCursor](qlistwidget.md#setcursor)
* [setDefaultDropAction](qlistwidget.md#setdefaultdropaction)
* [setDragDropMode](qlistwidget.md#setdragdropmode)
* [setDragDropOverwriteMode](qlistwidget.md#setdragdropoverwritemode)
* [setDragEnabled](qlistwidget.md#setdragenabled)
* [setDropIndicatorShown](qlistwidget.md#setdropindicatorshown)
* [setEditTriggers](qlistwidget.md#setedittriggers)
* [setEnabled](qlistwidget.md#setenabled)
* [setFixedSize](qlistwidget.md#setfixedsize)
* [setFlexNodeSizeControlled](qlistwidget.md#setflexnodesizecontrolled)
* [setFlow](qlistwidget.md#setflow)
* [setFocus](qlistwidget.md#setfocus)
* [setFocusPolicy](qlistwidget.md#setfocuspolicy)
* [setFont](qlistwidget.md#setfont)
* [setFrameRect](qlistwidget.md#setframerect)
* [setFrameShadow](qlistwidget.md#setframeshadow)
* [setFrameShape](qlistwidget.md#setframeshape)
* [setFrameStyle](qlistwidget.md#setframestyle)
* [setGeometry](qlistwidget.md#setgeometry)
* [setGraphicsEffect](qlistwidget.md#setgraphicseffect)
* [setGridSize](qlistwidget.md#setgridsize)
* [setHorizontalScrollBar](qlistwidget.md#sethorizontalscrollbar)
* [setHorizontalScrollBarPolicy](qlistwidget.md#sethorizontalscrollbarpolicy)
* [setHorizontalScrollMode](qlistwidget.md#sethorizontalscrollmode)
* [setIconSize](qlistwidget.md#seticonsize)
* [setIndexWidget](qlistwidget.md#setindexwidget)
* [setInlineStyle](qlistwidget.md#setinlinestyle)
* [setItemAlignment](qlistwidget.md#setitemalignment)
* [setItemWidget](qlistwidget.md#setitemwidget)
* [setLayout](qlistwidget.md#setlayout)
* [setLayoutMode](qlistwidget.md#setlayoutmode)
* [setLineWidth](qlistwidget.md#setlinewidth)
* [setMaximumSize](qlistwidget.md#setmaximumsize)
* [setMidLineWidth](qlistwidget.md#setmidlinewidth)
* [setMinimumSize](qlistwidget.md#setminimumsize)
* [setModelColumn](qlistwidget.md#setmodelcolumn)
* [setMouseTracking](qlistwidget.md#setmousetracking)
* [setMovement](qlistwidget.md#setmovement)
* [setNodeParent](qlistwidget.md#setnodeparent)
* [setObjectName](qlistwidget.md#setobjectname)
* [setProperty](qlistwidget.md#setproperty)
* [setResizeMode](qlistwidget.md#setresizemode)
* [setRowHidden](qlistwidget.md#setrowhidden)
* [setSelectionBehavior](qlistwidget.md#setselectionbehavior)
* [setSelectionMode](qlistwidget.md#setselectionmode)
* [setSelectionRectVisible](qlistwidget.md#setselectionrectvisible)
* [setSortingEnabled](qlistwidget.md#setsortingenabled)
* [setSpacing](qlistwidget.md#setspacing)
* [setStyleSheet](qlistwidget.md#setstylesheet)
* [setTabKeyNavigation](qlistwidget.md#settabkeynavigation)
* [setTextElideMode](qlistwidget.md#settextelidemode)
* [setUniformItemSizes](qlistwidget.md#setuniformitemsizes)
* [setVerticalScrollBar](qlistwidget.md#setverticalscrollbar)
* [setVerticalScrollBarPolicy](qlistwidget.md#setverticalscrollbarpolicy)
* [setVerticalScrollMode](qlistwidget.md#setverticalscrollmode)
* [setViewMode](qlistwidget.md#setviewmode)
* [setViewport](qlistwidget.md#setviewport)
* [setWindowFlag](qlistwidget.md#setwindowflag)
* [setWindowIcon](qlistwidget.md#setwindowicon)
* [setWindowOpacity](qlistwidget.md#setwindowopacity)
* [setWindowState](qlistwidget.md#setwindowstate)
* [setWindowTitle](qlistwidget.md#setwindowtitle)
* [setWordWrap](qlistwidget.md#setwordwrap)
* [setWrapping](qlistwidget.md#setwrapping)
* [show](qlistwidget.md#show)
* [showDropIndicator](qlistwidget.md#showdropindicator)
* [showFullScreen](qlistwidget.md#showfullscreen)
* [showMaximized](qlistwidget.md#showmaximized)
* [showMinimized](qlistwidget.md#showminimized)
* [showNormal](qlistwidget.md#shownormal)
* [size](qlistwidget.md#size)
* [sortItems](qlistwidget.md#sortitems)
* [spacing](qlistwidget.md#spacing)
* [styleSheet](qlistwidget.md#stylesheet)
* [tabKeyNavigation](qlistwidget.md#tabkeynavigation)
* [takeItem](qlistwidget.md#takeitem)
* [testAttribute](qlistwidget.md#testattribute)
* [textElideMode](qlistwidget.md#textelidemode)
* [uniformItemSizes](qlistwidget.md#uniformitemsizes)
* [update](qlistwidget.md#update)
* [updateGeometry](qlistwidget.md#updategeometry)
* [verticalScrollMode](qlistwidget.md#verticalscrollmode)
* [viewMode](qlistwidget.md#viewmode)
* [viewport](qlistwidget.md#viewport)
* [visualItemRect](qlistwidget.md#visualitemrect)
* [windowOpacity](qlistwidget.md#windowopacity)
* [windowState](qlistwidget.md#windowstate)
* [windowTitle](qlistwidget.md#windowtitle)
* [wordWrap](qlistwidget.md#wordwrap)

## Constructors

###  constructor

\+ **new QListWidget**(): *[QListWidget](qlistwidget.md)*

*Overrides [NodeWidget](nodewidget.md).[constructor](nodewidget.md#constructor)*

**Returns:** *[QListWidget](qlistwidget.md)*

\+ **new QListWidget**(`parent`: [NodeWidget](nodewidget.md)‹any›): *[QListWidget](qlistwidget.md)*

*Overrides [NodeWidget](nodewidget.md).[constructor](nodewidget.md#constructor)*

**Parameters:**

Name | Type |
------ | ------ |
`parent` | [NodeWidget](nodewidget.md)‹any› |

**Returns:** *[QListWidget](qlistwidget.md)*

## Properties

### `Optional` _layout

• **_layout**? : *[NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)›*

*Inherited from [QMenu](qmenu.md).[_layout](qmenu.md#optional-_layout)*

___

###  _rawInlineStyle

• **_rawInlineStyle**: *string* = ""

*Inherited from [QMenu](qmenu.md).[_rawInlineStyle](qmenu.md#_rawinlinestyle)*

___

###  actions

• **actions**: *Set‹[QAction](qaction.md)›*

*Inherited from [QMenu](qmenu.md).[actions](qmenu.md#actions)*

___

###  items

• **items**: *Set‹[NativeElement](../globals.md#nativeelement) | [Component](component.md)›*

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

• **type**: *string* = "widget"

*Inherited from [QMenu](qmenu.md).[type](qmenu.md#type)*

___

### `Optional` viewportWidget

• **viewportWidget**? : *[NodeWidget](nodewidget.md)‹any›*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[viewportWidget](qabstractscrollarea.md#optional-viewportwidget)*

## Accessors

###  layout

• **get layout**(): *[NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)› | undefined*

*Inherited from [QMenu](qmenu.md).[layout](qmenu.md#layout)*

**Returns:** *[NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)› | undefined*

• **set layout**(`l`: [NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)› | undefined): *void*

*Inherited from [QMenu](qmenu.md).[layout](qmenu.md#layout)*

**Parameters:**

Name | Type |
------ | ------ |
`l` | [NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)› &#124; undefined |

**Returns:** *void*

## Methods

###  acceptDrops

▸ **acceptDrops**(): *boolean*

*Inherited from [QMenu](qmenu.md).[acceptDrops](qmenu.md#acceptdrops)*

**Returns:** *boolean*

___

###  activateWindow

▸ **activateWindow**(): *void*

*Inherited from [QMenu](qmenu.md).[activateWindow](qmenu.md#activatewindow)*

**Returns:** *void*

___

###  addAction

▸ **addAction**(`action`: [QAction](qaction.md) | string): *[QAction](qaction.md)*

*Inherited from [QMenu](qmenu.md).[addAction](qmenu.md#addaction)*

**Parameters:**

Name | Type |
------ | ------ |
`action` | [QAction](qaction.md) &#124; string |

**Returns:** *[QAction](qaction.md)*

___

###  addEventListener

▸ **addEventListener**‹**SignalType**›(`signalType`: SignalType, `callback`: QListWidgetSignals[SignalType]): *void*

*Inherited from [EventWidget](eventwidget.md).[addEventListener](eventwidget.md#addeventlistener)*

**Type parameters:**

▪ **SignalType**: *keyof QListWidgetSignals*

**Parameters:**

Name | Type | Description |
------ | ------ | ------ |
`signalType` | SignalType | SignalType is a signal from the widgets signals interface. |
`callback` | QListWidgetSignals[SignalType] | Corresponding callback for the signal as mentioned in the widget's signal interface |

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

###  addItem

▸ **addItem**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *void*

___

###  addItems

▸ **addItems**(`labels`: string[]): *void*

**Parameters:**

Name | Type |
------ | ------ |
`labels` | string[] |

**Returns:** *void*

___

###  adjustSize

▸ **adjustSize**(): *void*

*Inherited from [QMenu](qmenu.md).[adjustSize](qmenu.md#adjustsize)*

**Returns:** *void*

___

###  alternatingRowColors

▸ **alternatingRowColors**(): *boolean*

*Inherited from [QAbstractItemView](qabstractitemview.md).[alternatingRowColors](qabstractitemview.md#alternatingrowcolors)*

**Returns:** *boolean*

___

###  autoScrollMargin

▸ **autoScrollMargin**(): *number*

*Inherited from [QAbstractItemView](qabstractitemview.md).[autoScrollMargin](qabstractitemview.md#autoscrollmargin)*

**Returns:** *number*

___

###  batchSize

▸ **batchSize**(): *number*

*Inherited from [NodeListView](nodelistview.md).[batchSize](nodelistview.md#batchsize)*

**Returns:** *number*

___

###  clear

▸ **clear**(): *void*

**Returns:** *void*

___

###  clearFocus

▸ **clearFocus**(): *void*

*Inherited from [QMenu](qmenu.md).[clearFocus](qmenu.md#clearfocus)*

**Returns:** *void*

___

###  clearPropertyFlags

▸ **clearPropertyFlags**(): *void*

*Inherited from [NodeListView](nodelistview.md).[clearPropertyFlags](nodelistview.md#clearpropertyflags)*

**Returns:** *void*

___

###  close

▸ **close**(): *boolean*

*Inherited from [QMenu](qmenu.md).[close](qmenu.md#close)*

**Returns:** *boolean*

___

###  closePersistentEditor

▸ **closePersistentEditor**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *void*

___

###  count

▸ **count**(): *number*

**Returns:** *number*

___

###  currentIndex

▸ **currentIndex**(): *[QModelIndex](qmodelindex.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[currentIndex](qabstractitemview.md#currentindex)*

**Returns:** *[QModelIndex](qmodelindex.md)*

___

###  currentItem

▸ **currentItem**(): *[QListWidgetItem](qlistwidgetitem.md)*

**Returns:** *[QListWidgetItem](qlistwidgetitem.md)*

___

###  currentRow

▸ **currentRow**(): *number*

**Returns:** *number*

___

###  defaultDropAction

▸ **defaultDropAction**(): *[DropAction](../enums/dropaction.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[defaultDropAction](qabstractitemview.md#defaultdropaction)*

**Returns:** *[DropAction](../enums/dropaction.md)*

___

###  dragDropMode

▸ **dragDropMode**(): *[DragDropMode](../enums/dragdropmode.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[dragDropMode](qabstractitemview.md#dragdropmode)*

**Returns:** *[DragDropMode](../enums/dragdropmode.md)*

___

###  dragDropOverwriteMode

▸ **dragDropOverwriteMode**(): *boolean*

*Inherited from [QAbstractItemView](qabstractitemview.md).[dragDropOverwriteMode](qabstractitemview.md#dragdropoverwritemode)*

**Returns:** *boolean*

___

###  dragEnabled

▸ **dragEnabled**(): *boolean*

*Inherited from [QAbstractItemView](qabstractitemview.md).[dragEnabled](qabstractitemview.md#dragenabled)*

**Returns:** *boolean*

___

###  editItem

▸ **editItem**(`item`: [Component](component.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [Component](component.md) |

**Returns:** *void*

___

###  editTriggers

▸ **editTriggers**(): *number*

*Inherited from [QAbstractItemView](qabstractitemview.md).[editTriggers](qabstractitemview.md#edittriggers)*

**Returns:** *number*

___

###  findItems

▸ **findItems**(`text`: string, `flags`: [MatchFlag](../enums/matchflag.md)): *[QListWidgetItem](qlistwidgetitem.md)[]*

**Parameters:**

Name | Type |
------ | ------ |
`text` | string |
`flags` | [MatchFlag](../enums/matchflag.md) |

**Returns:** *[QListWidgetItem](qlistwidgetitem.md)[]*

___

###  flow

▸ **flow**(): *[Flow](../enums/flow.md)*

*Inherited from [NodeListView](nodelistview.md).[flow](nodelistview.md#flow)*

**Returns:** *[Flow](../enums/flow.md)*

___

###  font

▸ **font**(): *[QFont](qfont.md)*

*Inherited from [QMenu](qmenu.md).[font](qmenu.md#font)*

**Returns:** *[QFont](qfont.md)*

___

###  frameRect

▸ **frameRect**(): *[QRect](qrect.md)*

*Inherited from [NodeFrame](nodeframe.md).[frameRect](nodeframe.md#framerect)*

**Returns:** *[QRect](qrect.md)*

___

###  frameShadow

▸ **frameShadow**(): *[Shadow](../enums/shadow.md)*

*Inherited from [NodeFrame](nodeframe.md).[frameShadow](nodeframe.md#frameshadow)*

**Returns:** *[Shadow](../enums/shadow.md)*

___

###  frameShape

▸ **frameShape**(): *[Shape](../enums/shape.md)*

*Inherited from [NodeFrame](nodeframe.md).[frameShape](nodeframe.md#frameshape)*

**Returns:** *[Shape](../enums/shape.md)*

___

###  frameStyle

▸ **frameStyle**(): *number*

*Inherited from [NodeFrame](nodeframe.md).[frameStyle](nodeframe.md#framestyle)*

**Returns:** *number*

___

###  frameWidth

▸ **frameWidth**(): *number*

*Inherited from [NodeFrame](nodeframe.md).[frameWidth](nodeframe.md#framewidth)*

**Returns:** *number*

___

###  geometry

▸ **geometry**(): *[QRect](qrect.md)*

*Inherited from [QMenu](qmenu.md).[geometry](qmenu.md#geometry)*

**Returns:** *[QRect](qrect.md)*

___

###  getFlexNode

▸ **getFlexNode**(): *[FlexNode](../globals.md#flexnode)*

*Inherited from [YogaWidget](yogawidget.md).[getFlexNode](yogawidget.md#getflexnode)*

**Returns:** *[FlexNode](../globals.md#flexnode)*

___

###  gridSize

▸ **gridSize**(): *[QSize](qsize.md)*

*Inherited from [NodeListView](nodelistview.md).[gridSize](nodelistview.md#gridsize)*

**Returns:** *[QSize](qsize.md)*

___

###  hasAutoScroll

▸ **hasAutoScroll**(): *boolean*

*Inherited from [QAbstractItemView](qabstractitemview.md).[hasAutoScroll](qabstractitemview.md#hasautoscroll)*

**Returns:** *boolean*

___

###  hasMouseTracking

▸ **hasMouseTracking**(): *boolean*

*Inherited from [QMenu](qmenu.md).[hasMouseTracking](qmenu.md#hasmousetracking)*

**Returns:** *boolean*

___

###  hide

▸ **hide**(): *void*

*Inherited from [QMenu](qmenu.md).[hide](qmenu.md#hide)*

**Returns:** *void*

___

###  horizontalScrollMode

▸ **horizontalScrollMode**(): *[ScrollMode](../enums/scrollmode.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[horizontalScrollMode](qabstractitemview.md#horizontalscrollmode)*

**Returns:** *[ScrollMode](../enums/scrollmode.md)*

___

###  iconSize

▸ **iconSize**(): *[QSize](qsize.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[iconSize](qabstractitemview.md#iconsize)*

**Returns:** *[QSize](qsize.md)*

___

###  indexWidget

▸ **indexWidget**(`index`: [QModelIndex](qmodelindex.md)): *[QWidget](qwidget.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[indexWidget](qabstractitemview.md#indexwidget)*

**Parameters:**

Name | Type |
------ | ------ |
`index` | [QModelIndex](qmodelindex.md) |

**Returns:** *[QWidget](qwidget.md)*

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

###  insertItem

▸ **insertItem**(`row`: number, `item`: [QListWidgetItem](qlistwidgetitem.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *void*

___

###  insertItems

▸ **insertItems**(`row`: number, `labels`: string[]): *void*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |
`labels` | string[] |

**Returns:** *void*

___

###  isActiveWindow

▸ **isActiveWindow**(): *boolean*

*Inherited from [QMenu](qmenu.md).[isActiveWindow](qmenu.md#isactivewindow)*

**Returns:** *boolean*

___

###  isEnabled

▸ **isEnabled**(): *boolean*

*Inherited from [QMenu](qmenu.md).[isEnabled](qmenu.md#isenabled)*

**Returns:** *boolean*

___

###  isPersistentEditorOpen

▸ **isPersistentEditorOpen**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *boolean*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *boolean*

___

###  isRowHidden

▸ **isRowHidden**(`row`: number): *boolean*

*Inherited from [NodeListView](nodelistview.md).[isRowHidden](nodelistview.md#isrowhidden)*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |

**Returns:** *boolean*

___

###  isSelectionRectVisible

▸ **isSelectionRectVisible**(): *boolean*

*Inherited from [NodeListView](nodelistview.md).[isSelectionRectVisible](nodelistview.md#isselectionrectvisible)*

**Returns:** *boolean*

___

###  isSortingEnabled

▸ **isSortingEnabled**(): *boolean*

**Returns:** *boolean*

___

###  isVisible

▸ **isVisible**(): *boolean*

*Inherited from [QMenu](qmenu.md).[isVisible](qmenu.md#isvisible)*

**Returns:** *boolean*

___

###  isWrapping

▸ **isWrapping**(): *boolean*

*Inherited from [NodeListView](nodelistview.md).[isWrapping](nodelistview.md#iswrapping)*

**Returns:** *boolean*

___

###  item

▸ **item**(`row`: number): *[QListWidgetItem](qlistwidgetitem.md)*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |

**Returns:** *[QListWidgetItem](qlistwidgetitem.md)*

___

###  itemAlignment

▸ **itemAlignment**(): *[AlignmentFlag](../enums/alignmentflag.md)*

*Inherited from [NodeListView](nodelistview.md).[itemAlignment](nodelistview.md#itemalignment)*

**Returns:** *[AlignmentFlag](../enums/alignmentflag.md)*

___

###  itemAt

▸ **itemAt**(`x`: number, `y`: number): *[QListWidgetItem](qlistwidgetitem.md)*

**Parameters:**

Name | Type |
------ | ------ |
`x` | number |
`y` | number |

**Returns:** *[QListWidgetItem](qlistwidgetitem.md)*

___

###  itemWidget

▸ **itemWidget**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *[QWidget](qwidget.md)*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *[QWidget](qwidget.md)*

___

###  layoutMode

▸ **layoutMode**(): *[LayoutMode](../enums/layoutmode.md)*

*Inherited from [NodeListView](nodelistview.md).[layoutMode](nodelistview.md#layoutmode)*

**Returns:** *[LayoutMode](../enums/layoutmode.md)*

___

###  lineWidth

▸ **lineWidth**(): *number*

*Inherited from [NodeFrame](nodeframe.md).[lineWidth](nodeframe.md#linewidth)*

**Returns:** *number*

___

###  lower

▸ **lower**(): *void*

*Inherited from [QMenu](qmenu.md).[lower](qmenu.md#lower)*

**Returns:** *void*

___

###  mapFromGlobal

▸ **mapFromGlobal**(`pos`: [QPoint](qpoint.md)): *[QPoint](qpoint.md)*

*Inherited from [QMenu](qmenu.md).[mapFromGlobal](qmenu.md#mapfromglobal)*

**Parameters:**

Name | Type |
------ | ------ |
`pos` | [QPoint](qpoint.md) |

**Returns:** *[QPoint](qpoint.md)*

___

###  mapFromParent

▸ **mapFromParent**(`pos`: [QPoint](qpoint.md)): *[QPoint](qpoint.md)*

*Inherited from [QMenu](qmenu.md).[mapFromParent](qmenu.md#mapfromparent)*

**Parameters:**

Name | Type |
------ | ------ |
`pos` | [QPoint](qpoint.md) |

**Returns:** *[QPoint](qpoint.md)*

___

###  mapToGlobal

▸ **mapToGlobal**(`pos`: [QPoint](qpoint.md)): *[QPoint](qpoint.md)*

*Inherited from [QMenu](qmenu.md).[mapToGlobal](qmenu.md#maptoglobal)*

**Parameters:**

Name | Type |
------ | ------ |
`pos` | [QPoint](qpoint.md) |

**Returns:** *[QPoint](qpoint.md)*

___

###  mapToParent

▸ **mapToParent**(`pos`: [QPoint](qpoint.md)): *[QPoint](qpoint.md)*

*Inherited from [QMenu](qmenu.md).[mapToParent](qmenu.md#maptoparent)*

**Parameters:**

Name | Type |
------ | ------ |
`pos` | [QPoint](qpoint.md) |

**Returns:** *[QPoint](qpoint.md)*

___

###  maximumSize

▸ **maximumSize**(): *[QSize](qsize.md)*

*Inherited from [QMenu](qmenu.md).[maximumSize](qmenu.md#maximumsize)*

**Returns:** *[QSize](qsize.md)*

___

###  maximumViewportSize

▸ **maximumViewportSize**(): *[QSize](qsize.md)*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[maximumViewportSize](qabstractscrollarea.md#maximumviewportsize)*

**Returns:** *[QSize](qsize.md)*

___

###  midLineWidth

▸ **midLineWidth**(): *number*

*Inherited from [NodeFrame](nodeframe.md).[midLineWidth](nodeframe.md#midlinewidth)*

**Returns:** *number*

___

###  minimumSize

▸ **minimumSize**(): *[QSize](qsize.md)*

*Inherited from [QMenu](qmenu.md).[minimumSize](qmenu.md#minimumsize)*

**Returns:** *[QSize](qsize.md)*

___

###  modelColumn

▸ **modelColumn**(): *number*

*Inherited from [NodeListView](nodelistview.md).[modelColumn](nodelistview.md#modelcolumn)*

**Returns:** *number*

___

###  move

▸ **move**(`x`: number, `y`: number): *void*

*Inherited from [QMenu](qmenu.md).[move](qmenu.md#move)*

**Parameters:**

Name | Type |
------ | ------ |
`x` | number |
`y` | number |

**Returns:** *void*

___

###  movement

▸ **movement**(): *[Movement](../enums/movement.md)*

*Inherited from [NodeListView](nodelistview.md).[movement](nodelistview.md#movement)*

**Returns:** *[Movement](../enums/movement.md)*

___

###  objectName

▸ **objectName**(): *string*

*Inherited from [NodeObject](nodeobject.md).[objectName](nodeobject.md#objectname)*

**Returns:** *string*

___

###  openPersistentEditor

▸ **openPersistentEditor**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *void*

___

###  pos

▸ **pos**(): *object*

*Inherited from [QMenu](qmenu.md).[pos](qmenu.md#pos)*

**Returns:** *object*

* **x**: *number*

* **y**: *number*

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

###  raise

▸ **raise**(): *void*

*Inherited from [QMenu](qmenu.md).[raise](qmenu.md#raise)*

**Returns:** *void*

___

###  removeAction

▸ **removeAction**(`action`: [QAction](qaction.md)): *void*

*Inherited from [QMenu](qmenu.md).[removeAction](qmenu.md#removeaction)*

**Parameters:**

Name | Type |
------ | ------ |
`action` | [QAction](qaction.md) |

**Returns:** *void*

___

###  removeEventListener

▸ **removeEventListener**‹**SignalType**›(`signalType`: SignalType, `callback`: QListWidgetSignals[SignalType]): *void*

*Inherited from [EventWidget](eventwidget.md).[removeEventListener](eventwidget.md#removeeventlistener)*

**Type parameters:**

▪ **SignalType**: *keyof QListWidgetSignals*

**Parameters:**

Name | Type |
------ | ------ |
`signalType` | SignalType |
`callback` | QListWidgetSignals[SignalType] |

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

###  removeItemWidget

▸ **removeItemWidget**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *void*

___

###  repaint

▸ **repaint**(): *void*

*Inherited from [QMenu](qmenu.md).[repaint](qmenu.md#repaint)*

**Returns:** *void*

___

###  repolish

▸ **repolish**(): *void*

*Inherited from [QMenu](qmenu.md).[repolish](qmenu.md#repolish)*

**Returns:** *void*

___

###  resetHorizontalScrollMode

▸ **resetHorizontalScrollMode**(): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[resetHorizontalScrollMode](qabstractitemview.md#resethorizontalscrollmode)*

**Returns:** *void*

___

###  resetVerticalScrollMode

▸ **resetVerticalScrollMode**(): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[resetVerticalScrollMode](qabstractitemview.md#resetverticalscrollmode)*

**Returns:** *void*

___

###  resize

▸ **resize**(`width`: number, `height`: number): *void*

*Inherited from [QMenu](qmenu.md).[resize](qmenu.md#resize)*

**Parameters:**

Name | Type |
------ | ------ |
`width` | number |
`height` | number |

**Returns:** *void*

___

###  resizeMode

▸ **resizeMode**(): *[ResizeMode](../enums/resizemode.md)*

*Inherited from [NodeListView](nodelistview.md).[resizeMode](nodelistview.md#resizemode)*

**Returns:** *[ResizeMode](../enums/resizemode.md)*

___

###  row

▸ **row**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *number*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *number*

___

###  scrollToBottom

▸ **scrollToBottom**(): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[scrollToBottom](qabstractitemview.md#scrolltobottom)*

**Returns:** *void*

___

###  scrollToItem

▸ **scrollToItem**(`item`: [QListWidgetItem](qlistwidgetitem.md), `hint`: [ScrollHint](../enums/scrollhint.md)): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) | - |
`hint` | [ScrollHint](../enums/scrollhint.md) | ScrollHint.EnsureVisible |

**Returns:** *void*

___

###  scrollToTop

▸ **scrollToTop**(): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[scrollToTop](qabstractitemview.md#scrolltotop)*

**Returns:** *void*

___

###  selectedItems

▸ **selectedItems**(): *[QListWidgetItem](qlistwidgetitem.md)[]*

**Returns:** *[QListWidgetItem](qlistwidgetitem.md)[]*

___

###  selectionBehavior

▸ **selectionBehavior**(): *[SelectionBehavior](../enums/selectionbehavior.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[selectionBehavior](qabstractitemview.md#selectionbehavior)*

**Returns:** *[SelectionBehavior](../enums/selectionbehavior.md)*

___

###  selectionMode

▸ **selectionMode**(): *[SelectionMode](../enums/selectionmode.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[selectionMode](qabstractitemview.md#selectionmode)*

**Returns:** *[SelectionMode](../enums/selectionmode.md)*

___

###  setAcceptDrops

▸ **setAcceptDrops**(`on`: boolean): *void*

*Inherited from [QMenu](qmenu.md).[setAcceptDrops](qmenu.md#setacceptdrops)*

**Parameters:**

Name | Type |
------ | ------ |
`on` | boolean |

**Returns:** *void*

___

###  setAlternatingRowColors

▸ **setAlternatingRowColors**(`enable`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setAlternatingRowColors](qabstractitemview.md#setalternatingrowcolors)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setAttribute

▸ **setAttribute**(`attribute`: [WidgetAttribute](../enums/widgetattribute.md), `switchOn`: boolean): *void*

*Inherited from [QMenu](qmenu.md).[setAttribute](qmenu.md#setattribute)*

**Parameters:**

Name | Type |
------ | ------ |
`attribute` | [WidgetAttribute](../enums/widgetattribute.md) |
`switchOn` | boolean |

**Returns:** *void*

___

###  setAutoScroll

▸ **setAutoScroll**(`enable`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setAutoScroll](qabstractitemview.md#setautoscroll)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setAutoScrollMargin

▸ **setAutoScrollMargin**(`margin`: number): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setAutoScrollMargin](qabstractitemview.md#setautoscrollmargin)*

**Parameters:**

Name | Type |
------ | ------ |
`margin` | number |

**Returns:** *void*

___

###  setBatchSize

▸ **setBatchSize**(`batchSize`: number): *void*

*Inherited from [NodeListView](nodelistview.md).[setBatchSize](nodelistview.md#setbatchsize)*

**Parameters:**

Name | Type |
------ | ------ |
`batchSize` | number |

**Returns:** *void*

___

###  setContextMenuPolicy

▸ **setContextMenuPolicy**(`contextMenuPolicy`: [ContextMenuPolicy](../enums/contextmenupolicy.md)): *void*

*Inherited from [QMenu](qmenu.md).[setContextMenuPolicy](qmenu.md#setcontextmenupolicy)*

**Parameters:**

Name | Type |
------ | ------ |
`contextMenuPolicy` | [ContextMenuPolicy](../enums/contextmenupolicy.md) |

**Returns:** *void*

___

###  setCurrentIndex

▸ **setCurrentIndex**(`index`: [QModelIndex](qmodelindex.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setCurrentIndex](qabstractitemview.md#setcurrentindex)*

**Parameters:**

Name | Type |
------ | ------ |
`index` | [QModelIndex](qmodelindex.md) |

**Returns:** *void*

___

###  setCurrentItem

▸ **setCurrentItem**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *void*

___

###  setCurrentRow

▸ **setCurrentRow**(`row`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |

**Returns:** *void*

___

###  setCursor

▸ **setCursor**(`cursor`: [CursorShape](../enums/cursorshape.md) | [QCursor](qcursor.md)): *void*

*Inherited from [QMenu](qmenu.md).[setCursor](qmenu.md#setcursor)*

**Parameters:**

Name | Type |
------ | ------ |
`cursor` | [CursorShape](../enums/cursorshape.md) &#124; [QCursor](qcursor.md) |

**Returns:** *void*

___

###  setDefaultDropAction

▸ **setDefaultDropAction**(`dropAction`: [DropAction](../enums/dropaction.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setDefaultDropAction](qabstractitemview.md#setdefaultdropaction)*

**Parameters:**

Name | Type |
------ | ------ |
`dropAction` | [DropAction](../enums/dropaction.md) |

**Returns:** *void*

___

###  setDragDropMode

▸ **setDragDropMode**(`behavior`: [DragDropMode](../enums/dragdropmode.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setDragDropMode](qabstractitemview.md#setdragdropmode)*

**Parameters:**

Name | Type |
------ | ------ |
`behavior` | [DragDropMode](../enums/dragdropmode.md) |

**Returns:** *void*

___

###  setDragDropOverwriteMode

▸ **setDragDropOverwriteMode**(`overwrite`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setDragDropOverwriteMode](qabstractitemview.md#setdragdropoverwritemode)*

**Parameters:**

Name | Type |
------ | ------ |
`overwrite` | boolean |

**Returns:** *void*

___

###  setDragEnabled

▸ **setDragEnabled**(`enable`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setDragEnabled](qabstractitemview.md#setdragenabled)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setDropIndicatorShown

▸ **setDropIndicatorShown**(`enable`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setDropIndicatorShown](qabstractitemview.md#setdropindicatorshown)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setEditTriggers

▸ **setEditTriggers**(`triggers`: number): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setEditTriggers](qabstractitemview.md#setedittriggers)*

**Parameters:**

Name | Type |
------ | ------ |
`triggers` | number |

**Returns:** *void*

___

###  setEnabled

▸ **setEnabled**(`enabled`: boolean): *void*

*Inherited from [QMenu](qmenu.md).[setEnabled](qmenu.md#setenabled)*

**Parameters:**

Name | Type |
------ | ------ |
`enabled` | boolean |

**Returns:** *void*

___

###  setFixedSize

▸ **setFixedSize**(`width`: number, `height`: number): *void*

*Inherited from [QMenu](qmenu.md).[setFixedSize](qmenu.md#setfixedsize)*

**Parameters:**

Name | Type |
------ | ------ |
`width` | number |
`height` | number |

**Returns:** *void*

___

###  setFlexNodeSizeControlled

▸ **setFlexNodeSizeControlled**(`isSizeControlled`: boolean): *void*

*Inherited from [YogaWidget](yogawidget.md).[setFlexNodeSizeControlled](yogawidget.md#setflexnodesizecontrolled)*

sets whether the widget's size is controlled by someone else (for example a window's size is controlled by its frame when dragged).

**Parameters:**

Name | Type | Description |
------ | ------ | ------ |
`isSizeControlled` | boolean |   |

**Returns:** *void*

___

###  setFlow

▸ **setFlow**(`flow`: [Flow](../enums/flow.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setFlow](nodelistview.md#setflow)*

**Parameters:**

Name | Type |
------ | ------ |
`flow` | [Flow](../enums/flow.md) |

**Returns:** *void*

___

###  setFocus

▸ **setFocus**(`reason`: [FocusReason](../enums/focusreason.md)): *void*

*Inherited from [QMenu](qmenu.md).[setFocus](qmenu.md#setfocus)*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`reason` | [FocusReason](../enums/focusreason.md) | FocusReason.OtherFocusReason |

**Returns:** *void*

___

###  setFocusPolicy

▸ **setFocusPolicy**(`policy`: [FocusPolicy](../enums/focuspolicy.md)): *void*

*Inherited from [QMenu](qmenu.md).[setFocusPolicy](qmenu.md#setfocuspolicy)*

**Parameters:**

Name | Type |
------ | ------ |
`policy` | [FocusPolicy](../enums/focuspolicy.md) |

**Returns:** *void*

___

###  setFont

▸ **setFont**(`font`: [QFont](qfont.md)): *void*

*Inherited from [QMenu](qmenu.md).[setFont](qmenu.md#setfont)*

**Parameters:**

Name | Type |
------ | ------ |
`font` | [QFont](qfont.md) |

**Returns:** *void*

___

###  setFrameRect

▸ **setFrameRect**(`r`: [QRect](qrect.md)): *void*

*Inherited from [NodeFrame](nodeframe.md).[setFrameRect](nodeframe.md#setframerect)*

**Parameters:**

Name | Type |
------ | ------ |
`r` | [QRect](qrect.md) |

**Returns:** *void*

___

###  setFrameShadow

▸ **setFrameShadow**(`type`: [Shadow](../enums/shadow.md)): *void*

*Inherited from [NodeFrame](nodeframe.md).[setFrameShadow](nodeframe.md#setframeshadow)*

**Parameters:**

Name | Type |
------ | ------ |
`type` | [Shadow](../enums/shadow.md) |

**Returns:** *void*

___

###  setFrameShape

▸ **setFrameShape**(`type`: [Shape](../enums/shape.md)): *void*

*Inherited from [NodeFrame](nodeframe.md).[setFrameShape](nodeframe.md#setframeshape)*

**Parameters:**

Name | Type |
------ | ------ |
`type` | [Shape](../enums/shape.md) |

**Returns:** *void*

___

###  setFrameStyle

▸ **setFrameStyle**(`style`: number): *void*

*Inherited from [NodeFrame](nodeframe.md).[setFrameStyle](nodeframe.md#setframestyle)*

**Parameters:**

Name | Type |
------ | ------ |
`style` | number |

**Returns:** *void*

___

###  setGeometry

▸ **setGeometry**(`x`: number, `y`: number, `w`: number, `h`: number): *void*

*Inherited from [QMenu](qmenu.md).[setGeometry](qmenu.md#setgeometry)*

**Parameters:**

Name | Type |
------ | ------ |
`x` | number |
`y` | number |
`w` | number |
`h` | number |

**Returns:** *void*

___

###  setGraphicsEffect

▸ **setGraphicsEffect**(`effect`: [QGraphicsEffect](qgraphicseffect.md)‹any›): *void*

*Inherited from [QMenu](qmenu.md).[setGraphicsEffect](qmenu.md#setgraphicseffect)*

**Parameters:**

Name | Type |
------ | ------ |
`effect` | [QGraphicsEffect](qgraphicseffect.md)‹any› |

**Returns:** *void*

___

###  setGridSize

▸ **setGridSize**(`size`: [QSize](qsize.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setGridSize](nodelistview.md#setgridsize)*

**Parameters:**

Name | Type |
------ | ------ |
`size` | [QSize](qsize.md) |

**Returns:** *void*

___

###  setHorizontalScrollBar

▸ **setHorizontalScrollBar**(`scrollBar`: [QScrollBar](qscrollbar.md)): *void*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[setHorizontalScrollBar](qabstractscrollarea.md#sethorizontalscrollbar)*

**Parameters:**

Name | Type |
------ | ------ |
`scrollBar` | [QScrollBar](qscrollbar.md) |

**Returns:** *void*

___

###  setHorizontalScrollBarPolicy

▸ **setHorizontalScrollBarPolicy**(`policy`: [ScrollBarPolicy](../enums/scrollbarpolicy.md)): *void*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[setHorizontalScrollBarPolicy](qabstractscrollarea.md#sethorizontalscrollbarpolicy)*

**Parameters:**

Name | Type |
------ | ------ |
`policy` | [ScrollBarPolicy](../enums/scrollbarpolicy.md) |

**Returns:** *void*

___

###  setHorizontalScrollMode

▸ **setHorizontalScrollMode**(`mode`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setHorizontalScrollMode](qabstractitemview.md#sethorizontalscrollmode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | boolean |

**Returns:** *void*

___

###  setIconSize

▸ **setIconSize**(`iconSize`: [QSize](qsize.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setIconSize](qabstractitemview.md#seticonsize)*

**Parameters:**

Name | Type |
------ | ------ |
`iconSize` | [QSize](qsize.md) |

**Returns:** *void*

___

###  setIndexWidget

▸ **setIndexWidget**(`index`: [QModelIndex](qmodelindex.md), `widget`: [QWidget](qwidget.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setIndexWidget](qabstractitemview.md#setindexwidget)*

**Parameters:**

Name | Type |
------ | ------ |
`index` | [QModelIndex](qmodelindex.md) |
`widget` | [QWidget](qwidget.md) |

**Returns:** *void*

___

###  setInlineStyle

▸ **setInlineStyle**(`style`: string): *void*

*Inherited from [QMenu](qmenu.md).[setInlineStyle](qmenu.md#setinlinestyle)*

**Parameters:**

Name | Type |
------ | ------ |
`style` | string |

**Returns:** *void*

___

###  setItemAlignment

▸ **setItemAlignment**(`alignment`: [AlignmentFlag](../enums/alignmentflag.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setItemAlignment](nodelistview.md#setitemalignment)*

**Parameters:**

Name | Type |
------ | ------ |
`alignment` | [AlignmentFlag](../enums/alignmentflag.md) |

**Returns:** *void*

___

###  setItemWidget

▸ **setItemWidget**(`item`: [QListWidgetItem](qlistwidgetitem.md), `widget`: [NodeWidget](nodewidget.md)‹any›): *void*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |
`widget` | [NodeWidget](nodewidget.md)‹any› |

**Returns:** *void*

___

###  setLayout

▸ **setLayout**(`parentLayout`: [NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)›): *void*

*Inherited from [QMenu](qmenu.md).[setLayout](qmenu.md#setlayout)*

**Parameters:**

Name | Type |
------ | ------ |
`parentLayout` | [NodeLayout](nodelayout.md)‹[QListWidgetSignals](../interfaces/qlistwidgetsignals.md)› |

**Returns:** *void*

___

###  setLayoutMode

▸ **setLayoutMode**(`mode`: [LayoutMode](../enums/layoutmode.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setLayoutMode](nodelistview.md#setlayoutmode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | [LayoutMode](../enums/layoutmode.md) |

**Returns:** *void*

___

###  setLineWidth

▸ **setLineWidth**(`width`: number): *void*

*Inherited from [NodeFrame](nodeframe.md).[setLineWidth](nodeframe.md#setlinewidth)*

**Parameters:**

Name | Type |
------ | ------ |
`width` | number |

**Returns:** *void*

___

###  setMaximumSize

▸ **setMaximumSize**(`maxw`: number, `maxh`: number): *void*

*Inherited from [QMenu](qmenu.md).[setMaximumSize](qmenu.md#setmaximumsize)*

**Parameters:**

Name | Type |
------ | ------ |
`maxw` | number |
`maxh` | number |

**Returns:** *void*

___

###  setMidLineWidth

▸ **setMidLineWidth**(`width`: number): *void*

*Inherited from [NodeFrame](nodeframe.md).[setMidLineWidth](nodeframe.md#setmidlinewidth)*

**Parameters:**

Name | Type |
------ | ------ |
`width` | number |

**Returns:** *void*

___

###  setMinimumSize

▸ **setMinimumSize**(`minw`: number, `minh`: number): *void*

*Inherited from [QMenu](qmenu.md).[setMinimumSize](qmenu.md#setminimumsize)*

**Parameters:**

Name | Type |
------ | ------ |
`minw` | number |
`minh` | number |

**Returns:** *void*

___

###  setModelColumn

▸ **setModelColumn**(`column`: number): *void*

*Inherited from [NodeListView](nodelistview.md).[setModelColumn](nodelistview.md#setmodelcolumn)*

**Parameters:**

Name | Type |
------ | ------ |
`column` | number |

**Returns:** *void*

___

###  setMouseTracking

▸ **setMouseTracking**(`isMouseTracked`: boolean): *void*

*Inherited from [QMenu](qmenu.md).[setMouseTracking](qmenu.md#setmousetracking)*

**Parameters:**

Name | Type |
------ | ------ |
`isMouseTracked` | boolean |

**Returns:** *void*

___

###  setMovement

▸ **setMovement**(`movement`: [Movement](../enums/movement.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setMovement](nodelistview.md#setmovement)*

**Parameters:**

Name | Type |
------ | ------ |
`movement` | [Movement](../enums/movement.md) |

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

*Inherited from [QMenu](qmenu.md).[setObjectName](qmenu.md#setobjectname)*

*Overrides [NodeObject](nodeobject.md).[setObjectName](nodeobject.md#setobjectname)*

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

###  setResizeMode

▸ **setResizeMode**(`mode`: [ResizeMode](../enums/resizemode.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setResizeMode](nodelistview.md#setresizemode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | [ResizeMode](../enums/resizemode.md) |

**Returns:** *void*

___

###  setRowHidden

▸ **setRowHidden**(`row`: number, `hide`: boolean): *void*

*Inherited from [NodeListView](nodelistview.md).[setRowHidden](nodelistview.md#setrowhidden)*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |
`hide` | boolean |

**Returns:** *void*

___

###  setSelectionBehavior

▸ **setSelectionBehavior**(`behavior`: [SelectionBehavior](../enums/selectionbehavior.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setSelectionBehavior](qabstractitemview.md#setselectionbehavior)*

**Parameters:**

Name | Type |
------ | ------ |
`behavior` | [SelectionBehavior](../enums/selectionbehavior.md) |

**Returns:** *void*

___

###  setSelectionMode

▸ **setSelectionMode**(`mode`: [SelectionMode](../enums/selectionmode.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setSelectionMode](qabstractitemview.md#setselectionmode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | [SelectionMode](../enums/selectionmode.md) |

**Returns:** *void*

___

###  setSelectionRectVisible

▸ **setSelectionRectVisible**(`show`: boolean): *void*

*Inherited from [NodeListView](nodelistview.md).[setSelectionRectVisible](nodelistview.md#setselectionrectvisible)*

**Parameters:**

Name | Type |
------ | ------ |
`show` | boolean |

**Returns:** *void*

___

###  setSortingEnabled

▸ **setSortingEnabled**(`enable`: boolean): *void*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setSpacing

▸ **setSpacing**(`space`: number): *void*

*Inherited from [NodeListView](nodelistview.md).[setSpacing](nodelistview.md#setspacing)*

**Parameters:**

Name | Type |
------ | ------ |
`space` | number |

**Returns:** *void*

___

###  setStyleSheet

▸ **setStyleSheet**(`styleSheet`: string): *void*

*Inherited from [QMenu](qmenu.md).[setStyleSheet](qmenu.md#setstylesheet)*

**Parameters:**

Name | Type |
------ | ------ |
`styleSheet` | string |

**Returns:** *void*

___

###  setTabKeyNavigation

▸ **setTabKeyNavigation**(`enable`: boolean): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setTabKeyNavigation](qabstractitemview.md#settabkeynavigation)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setTextElideMode

▸ **setTextElideMode**(`mode`: [TextElideMode](../enums/textelidemode.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setTextElideMode](qabstractitemview.md#settextelidemode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | [TextElideMode](../enums/textelidemode.md) |

**Returns:** *void*

___

###  setUniformItemSizes

▸ **setUniformItemSizes**(`enable`: boolean): *void*

*Inherited from [NodeListView](nodelistview.md).[setUniformItemSizes](nodelistview.md#setuniformitemsizes)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  setVerticalScrollBar

▸ **setVerticalScrollBar**(`scrollBar`: [QScrollBar](qscrollbar.md)): *void*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[setVerticalScrollBar](qabstractscrollarea.md#setverticalscrollbar)*

**Parameters:**

Name | Type |
------ | ------ |
`scrollBar` | [QScrollBar](qscrollbar.md) |

**Returns:** *void*

___

###  setVerticalScrollBarPolicy

▸ **setVerticalScrollBarPolicy**(`policy`: [ScrollBarPolicy](../enums/scrollbarpolicy.md)): *void*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[setVerticalScrollBarPolicy](qabstractscrollarea.md#setverticalscrollbarpolicy)*

**Parameters:**

Name | Type |
------ | ------ |
`policy` | [ScrollBarPolicy](../enums/scrollbarpolicy.md) |

**Returns:** *void*

___

###  setVerticalScrollMode

▸ **setVerticalScrollMode**(`mode`: [ScrollMode](../enums/scrollmode.md)): *void*

*Inherited from [QAbstractItemView](qabstractitemview.md).[setVerticalScrollMode](qabstractitemview.md#setverticalscrollmode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | [ScrollMode](../enums/scrollmode.md) |

**Returns:** *void*

___

###  setViewMode

▸ **setViewMode**(`mode`: [ListViewMode](../enums/listviewmode.md)): *void*

*Inherited from [NodeListView](nodelistview.md).[setViewMode](nodelistview.md#setviewmode)*

**Parameters:**

Name | Type |
------ | ------ |
`mode` | [ListViewMode](../enums/listviewmode.md) |

**Returns:** *void*

___

###  setViewport

▸ **setViewport**(`widget`: [NodeWidget](nodewidget.md)‹any›): *void*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[setViewport](qabstractscrollarea.md#setviewport)*

**Parameters:**

Name | Type |
------ | ------ |
`widget` | [NodeWidget](nodewidget.md)‹any› |

**Returns:** *void*

___

###  setWindowFlag

▸ **setWindowFlag**(`windowType`: [WindowType](../enums/windowtype.md), `switchOn`: boolean): *void*

*Inherited from [QMenu](qmenu.md).[setWindowFlag](qmenu.md#setwindowflag)*

**Parameters:**

Name | Type |
------ | ------ |
`windowType` | [WindowType](../enums/windowtype.md) |
`switchOn` | boolean |

**Returns:** *void*

___

###  setWindowIcon

▸ **setWindowIcon**(`icon`: [QIcon](qicon.md)): *void*

*Inherited from [QMenu](qmenu.md).[setWindowIcon](qmenu.md#setwindowicon)*

**Parameters:**

Name | Type |
------ | ------ |
`icon` | [QIcon](qicon.md) |

**Returns:** *void*

___

###  setWindowOpacity

▸ **setWindowOpacity**(`opacity`: number): *void*

*Inherited from [QMenu](qmenu.md).[setWindowOpacity](qmenu.md#setwindowopacity)*

**Parameters:**

Name | Type |
------ | ------ |
`opacity` | number |

**Returns:** *void*

___

###  setWindowState

▸ **setWindowState**(`state`: [WindowState](../enums/windowstate.md)): *void*

*Inherited from [QMenu](qmenu.md).[setWindowState](qmenu.md#setwindowstate)*

**Parameters:**

Name | Type |
------ | ------ |
`state` | [WindowState](../enums/windowstate.md) |

**Returns:** *void*

___

###  setWindowTitle

▸ **setWindowTitle**(`title`: string): *void*

*Inherited from [QMenu](qmenu.md).[setWindowTitle](qmenu.md#setwindowtitle)*

**Parameters:**

Name | Type |
------ | ------ |
`title` | string |

**Returns:** *void*

___

###  setWordWrap

▸ **setWordWrap**(`on`: boolean): *void*

*Inherited from [NodeListView](nodelistview.md).[setWordWrap](nodelistview.md#setwordwrap)*

**Parameters:**

Name | Type |
------ | ------ |
`on` | boolean |

**Returns:** *void*

___

###  setWrapping

▸ **setWrapping**(`enable`: boolean): *void*

*Inherited from [NodeListView](nodelistview.md).[setWrapping](nodelistview.md#setwrapping)*

**Parameters:**

Name | Type |
------ | ------ |
`enable` | boolean |

**Returns:** *void*

___

###  show

▸ **show**(): *void*

*Inherited from [QMenu](qmenu.md).[show](qmenu.md#show)*

**Returns:** *void*

___

###  showDropIndicator

▸ **showDropIndicator**(): *boolean*

*Inherited from [QAbstractItemView](qabstractitemview.md).[showDropIndicator](qabstractitemview.md#showdropindicator)*

**Returns:** *boolean*

___

###  showFullScreen

▸ **showFullScreen**(): *void*

*Inherited from [QMenu](qmenu.md).[showFullScreen](qmenu.md#showfullscreen)*

**Returns:** *void*

___

###  showMaximized

▸ **showMaximized**(): *void*

*Inherited from [QMenu](qmenu.md).[showMaximized](qmenu.md#showmaximized)*

**Returns:** *void*

___

###  showMinimized

▸ **showMinimized**(): *void*

*Inherited from [QMenu](qmenu.md).[showMinimized](qmenu.md#showminimized)*

**Returns:** *void*

___

###  showNormal

▸ **showNormal**(): *void*

*Inherited from [QMenu](qmenu.md).[showNormal](qmenu.md#shownormal)*

**Returns:** *void*

___

###  size

▸ **size**(): *[QSize](qsize.md)*

*Inherited from [QMenu](qmenu.md).[size](qmenu.md#size)*

**Returns:** *[QSize](qsize.md)*

___

###  sortItems

▸ **sortItems**(`order`: [SortOrder](../enums/sortorder.md)): *void*

**Parameters:**

Name | Type | Default |
------ | ------ | ------ |
`order` | [SortOrder](../enums/sortorder.md) | SortOrder.AscendingOrder |

**Returns:** *void*

___

###  spacing

▸ **spacing**(): *number*

*Inherited from [NodeListView](nodelistview.md).[spacing](nodelistview.md#spacing)*

**Returns:** *number*

___

###  styleSheet

▸ **styleSheet**(): *string*

*Inherited from [QMenu](qmenu.md).[styleSheet](qmenu.md#stylesheet)*

**Returns:** *string*

___

###  tabKeyNavigation

▸ **tabKeyNavigation**(): *boolean*

*Inherited from [QAbstractItemView](qabstractitemview.md).[tabKeyNavigation](qabstractitemview.md#tabkeynavigation)*

**Returns:** *boolean*

___

###  takeItem

▸ **takeItem**(`row`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`row` | number |

**Returns:** *void*

___

###  testAttribute

▸ **testAttribute**(`attribute`: [WidgetAttribute](../enums/widgetattribute.md)): *boolean*

*Inherited from [QMenu](qmenu.md).[testAttribute](qmenu.md#testattribute)*

**Parameters:**

Name | Type |
------ | ------ |
`attribute` | [WidgetAttribute](../enums/widgetattribute.md) |

**Returns:** *boolean*

___

###  textElideMode

▸ **textElideMode**(): *[TextElideMode](../enums/textelidemode.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[textElideMode](qabstractitemview.md#textelidemode)*

**Returns:** *[TextElideMode](../enums/textelidemode.md)*

___

###  uniformItemSizes

▸ **uniformItemSizes**(): *boolean*

*Inherited from [NodeListView](nodelistview.md).[uniformItemSizes](nodelistview.md#uniformitemsizes)*

**Returns:** *boolean*

___

###  update

▸ **update**(): *void*

*Inherited from [QMenu](qmenu.md).[update](qmenu.md#update)*

**Returns:** *void*

___

###  updateGeometry

▸ **updateGeometry**(): *void*

*Inherited from [QMenu](qmenu.md).[updateGeometry](qmenu.md#updategeometry)*

**Returns:** *void*

___

###  verticalScrollMode

▸ **verticalScrollMode**(): *[ScrollMode](../enums/scrollmode.md)*

*Inherited from [QAbstractItemView](qabstractitemview.md).[verticalScrollMode](qabstractitemview.md#verticalscrollmode)*

**Returns:** *[ScrollMode](../enums/scrollmode.md)*

___

###  viewMode

▸ **viewMode**(): *[ListViewMode](../enums/listviewmode.md)*

*Inherited from [NodeListView](nodelistview.md).[viewMode](nodelistview.md#viewmode)*

**Returns:** *[ListViewMode](../enums/listviewmode.md)*

___

###  viewport

▸ **viewport**(): *[QWidget](qwidget.md)*

*Inherited from [QAbstractScrollArea](qabstractscrollarea.md).[viewport](qabstractscrollarea.md#viewport)*

**Returns:** *[QWidget](qwidget.md)*

___

###  visualItemRect

▸ **visualItemRect**(`item`: [QListWidgetItem](qlistwidgetitem.md)): *[QRect](qrect.md)*

**Parameters:**

Name | Type |
------ | ------ |
`item` | [QListWidgetItem](qlistwidgetitem.md) |

**Returns:** *[QRect](qrect.md)*

___

###  windowOpacity

▸ **windowOpacity**(): *number*

*Inherited from [QMenu](qmenu.md).[windowOpacity](qmenu.md#windowopacity)*

**Returns:** *number*

___

###  windowState

▸ **windowState**(): *number*

*Inherited from [QMenu](qmenu.md).[windowState](qmenu.md#windowstate)*

**Returns:** *number*

___

###  windowTitle

▸ **windowTitle**(): *string*

*Inherited from [QMenu](qmenu.md).[windowTitle](qmenu.md#windowtitle)*

**Returns:** *string*

___

###  wordWrap

▸ **wordWrap**(): *boolean*

*Inherited from [NodeListView](nodelistview.md).[wordWrap](nodelistview.md#wordwrap)*

**Returns:** *boolean*
