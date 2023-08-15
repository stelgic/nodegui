---
id: "qfiledialogsignals"
title: "QFileDialogSignals"
sidebar_label: "QFileDialogSignals"
---

## Hierarchy

  ↳ [QDialogSignals](qdialogsignals.md)

  ↳ **QFileDialogSignals**

## Index

### Properties

* [accepted](qfiledialogsignals.md#accepted)
* [currentChanged](qfiledialogsignals.md#currentchanged)
* [currentUrlChanged](qfiledialogsignals.md#currenturlchanged)
* [customContextMenuRequested](qfiledialogsignals.md#customcontextmenurequested)
* [directoryEntered](qfiledialogsignals.md#directoryentered)
* [directoryUrlEntered](qfiledialogsignals.md#directoryurlentered)
* [fileSelected](qfiledialogsignals.md#fileselected)
* [filesSelected](qfiledialogsignals.md#filesselected)
* [filterSelected](qfiledialogsignals.md#filterselected)
* [finished](qfiledialogsignals.md#finished)
* [objectNameChanged](qfiledialogsignals.md#objectnamechanged)
* [rejected](qfiledialogsignals.md#rejected)
* [urlSelected](qfiledialogsignals.md#urlselected)
* [urlsSelected](qfiledialogsignals.md#urlsselected)
* [windowIconChanged](qfiledialogsignals.md#windowiconchanged)
* [windowTitleChanged](qfiledialogsignals.md#windowtitlechanged)

## Properties

###  accepted

• **accepted**: *function*

*Inherited from [QDialogSignals](qdialogsignals.md).[accepted](qdialogsignals.md#accepted)*

#### Type declaration:

▸ (): *void*

___

###  currentChanged

• **currentChanged**: *function*

#### Type declaration:

▸ (`path`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`path` | string |

___

###  currentUrlChanged

• **currentUrlChanged**: *function*

#### Type declaration:

▸ (`url`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`url` | string |

___

###  customContextMenuRequested

• **customContextMenuRequested**: *function*

*Inherited from [QMenuSignals](qmenusignals.md).[customContextMenuRequested](qmenusignals.md#customcontextmenurequested)*

#### Type declaration:

▸ (`pos`: object): *void*

**Parameters:**

▪ **pos**: *object*

Name | Type |
------ | ------ |
`x` | number |
`y` | number |

___

###  directoryEntered

• **directoryEntered**: *function*

#### Type declaration:

▸ (`directory`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`directory` | string |

___

###  directoryUrlEntered

• **directoryUrlEntered**: *function*

#### Type declaration:

▸ (`url`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`url` | string |

___

###  fileSelected

• **fileSelected**: *function*

#### Type declaration:

▸ (`file`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`file` | string |

___

###  filesSelected

• **filesSelected**: *function*

#### Type declaration:

▸ (`selected`: string[]): *void*

**Parameters:**

Name | Type |
------ | ------ |
`selected` | string[] |

___

###  filterSelected

• **filterSelected**: *function*

#### Type declaration:

▸ (`filter`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`filter` | string |

___

###  finished

• **finished**: *function*

*Inherited from [QDialogSignals](qdialogsignals.md).[finished](qdialogsignals.md#finished)*

#### Type declaration:

▸ (`result`: number): *void*

**Parameters:**

Name | Type |
------ | ------ |
`result` | number |

___

###  objectNameChanged

• **objectNameChanged**: *function*

*Inherited from [QObjectSignals](qobjectsignals.md).[objectNameChanged](qobjectsignals.md#objectnamechanged)*

#### Type declaration:

▸ (`objectName`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`objectName` | string |

___

###  rejected

• **rejected**: *function*

*Inherited from [QDialogSignals](qdialogsignals.md).[rejected](qdialogsignals.md#rejected)*

#### Type declaration:

▸ (): *void*

___

###  urlSelected

• **urlSelected**: *function*

#### Type declaration:

▸ (`url`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`url` | string |

___

###  urlsSelected

• **urlsSelected**: *function*

#### Type declaration:

▸ (`urls`: string[]): *void*

**Parameters:**

Name | Type |
------ | ------ |
`urls` | string[] |

___

###  windowIconChanged

• **windowIconChanged**: *function*

*Inherited from [QMenuSignals](qmenusignals.md).[windowIconChanged](qmenusignals.md#windowiconchanged)*

#### Type declaration:

▸ (`iconNative`: [NativeElement](../globals.md#nativeelement)): *void*

**Parameters:**

Name | Type |
------ | ------ |
`iconNative` | [NativeElement](../globals.md#nativeelement) |

___

###  windowTitleChanged

• **windowTitleChanged**: *function*

*Inherited from [QMenuSignals](qmenusignals.md).[windowTitleChanged](qmenusignals.md#windowtitlechanged)*

#### Type declaration:

▸ (`title`: string): *void*

**Parameters:**

Name | Type |
------ | ------ |
`title` | string |
