---
id: "component"
title: "Component"
sidebar_label: "Component"
---

> Abstract class that is root most base class for all widgets and layouts in the NodeGui World.

*This class is used to add core properties to all widgets, layouts etc in NodeGui world.
Currently it helps us maintain references to the native C++ instance of the widget or layout.
It also helps in preventing gc of child elements of a layout or widget**

`Component` is an abstract class and hence no instances of the same should be created.
It exists so that we can add core functionalities to all widgets and layouts easily. This is an internal class.

Its the root base class in NodeGui world.

## Hierarchy

* **Component**

  ↳ [QVariant](qvariant.md)

  ↳ [QSize](qsize.md)

  ↳ [QRect](qrect.md)

  ↳ [QPoint](qpoint.md)

  ↳ [QColor](qcolor.md)

  ↳ [QImage](qimage.md)

  ↳ [QPixmap](qpixmap.md)

  ↳ [QClipboard](qclipboard.md)

  ↳ [QStyle](qstyle.md)

  ↳ [EventWidget](eventwidget.md)

  ↳ [QIcon](qicon.md)

  ↳ [QCursor](qcursor.md)

  ↳ [QFont](qfont.md)

  ↳ [QKeySequence](qkeysequence.md)

  ↳ [QBrush](qbrush.md)

  ↳ [QPen](qpen.md)

  ↳ [QPicture](qpicture.md)

  ↳ [QFontDatabase](qfontdatabase.md)

  ↳ [QFontMetrics](qfontmetrics.md)

  ↳ [QUrl](qurl.md)

  ↳ [QMimeData](qmimedata.md)

  ↳ [QDrag](qdrag.md)

  ↳ [QModelIndex](qmodelindex.md)

  ↳ [QDate](qdate.md)

  ↳ [QTime](qtime.md)

  ↳ [QDateTime](qdatetime.md)

  ↳ [QStandardItem](qstandarditem.md)

  ↳ [QListWidgetItem](qlistwidgetitem.md)

  ↳ [QTableWidgetItem](qtablewidgetitem.md)

  ↳ [QTreeWidgetItem](qtreewidgetitem.md)

  ↳ [QPainterPath](qpainterpath.md)

  ↳ [QPainter](qpainter.md)

  ↳ [QPointF](qpointf.md)

  ↳ [QRectF](qrectf.md)

  ↳ [QSettings](qsettings.md)

## Index

### Constructors

* [constructor](component.md#constructor)

### Properties

* [native](component.md#abstract-native)
* [nodeChildren](component.md#nodechildren)
* [nodeParent](component.md#optional-nodeparent)

### Methods

* [setNodeParent](component.md#setnodeparent)

## Constructors

###  constructor

\+ **new Component**(): *[Component](component.md)*

**Returns:** *[Component](component.md)*

## Properties

### `Abstract` native

• **native**: *[NativeElement](../globals.md#nativeelement)*

___

###  nodeChildren

• **nodeChildren**: *Set‹[Component](component.md)›*

___

### `Optional` nodeParent

• **nodeParent**? : *[Component](component.md)*

## Methods

###  setNodeParent

▸ **setNodeParent**(`parent?`: [Component](component.md)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`parent?` | [Component](component.md) |

**Returns:** *void*
