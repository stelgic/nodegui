import addon from '../utils/addon';
import { QWidget, QWidgetSignals } from './QWidget';
import { QDialog, QDialogSignals } from './QDialog';
import { EchoMode } from './QLineEdit';
import { wrapperCache } from '../core/WrapperCache';
import { NativeElement } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';

/**

> Create and control input modal dialogs.

* **This class is a JS wrapper around Qt's [QInputDialog class](https://doc.qt.io/qt-5/qinputdialog.html)**

### Example

```javascript

import { QInputDialog } from '@nodegui/nodegui';

const dialog = new QInputDialog();
dialog.setLabelText('Click that Ok button');
dialog.exec();

```
 */
export class QInputDialog extends QDialog<QInputDialogSignals> {
    constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg != null) {
            const parent = arg as QWidget;
            native = new addon.QInputDialog(parent.native);
        } else {
            native = new addon.QInputDialog();
        }
        super(native);
    }
    setCancelButtonText(text: string): void {
        this.native.setCancelButtonText(text);
    }
    cancelButtonText(): string {
        return this.native.cancelButtonText();
    }
    setComboBoxEditable(editable: boolean): void {
        this.native.setComboxBoxEditable(editable);
    }
    isComboBoxEditable(): boolean {
        return this.native.isComboxBoxEditable();
    }
    setDoubleDecimals(decimals: number): void {
        this.native.setDoubleDecimals(decimals);
    }
    doubleDecimals(): number {
        return this.native.doubleDecimals();
    }
    setDoubleMaximum(value: number): void {
        this.native.setDoubleMaximum(value);
    }
    doubleMaximum(): number {
        return this.native.doubleMaximum();
    }
    setDoubleMinimum(value: number): void {
        this.native.setDoubleMinimum(value);
    }
    doubleMinimum(): number {
        return this.native.doubleMinimum();
    }
    doubleStep(): number {
        return this.native.doubleStep();
    }
    setDoubleStep(value: number): void {
        this.native.setDoubleStep(value);
    }
    doubleValue(): number {
        return this.native.doubleValue();
    }
    setDoubleValue(value: number): void {
        this.native.setDoubleValue(value);
    }
    inputMode(): InputMode {
        return this.native.inputMode();
    }
    setInputMode(value: InputMode): void {
        this.native.setInputMode(value);
    }
    intMaximum(): number {
        return this.native.intMaximum();
    }
    setIntMaximum(value: number): void {
        this.native.setIntMaximum(value);
    }
    intMinimum(): number {
        return this.native.intMinimum();
    }
    setIntMinimum(value: number): void {
        this.native.setIntMinimum(value);
    }
    intStep(): number {
        return this.native.intStep();
    }
    setIntStep(value: number): void {
        this.native.setIntStep(value);
    }
    intValue(): number {
        return this.native.intValue();
    }
    setIntValue(value: number): void {
        this.native.setIntValue(value);
    }
    labelText(): string {
        return this.native.labelText();
    }
    setLabelText(value: string): void {
        this.native.setLabelText(value);
    }
    okButtonText(): string {
        return this.native.okButtonText();
    }
    setOkButtonText(value: string): void {
        this.native.setOkButtonText(value);
    }
    options(): InputDialogOptions {
        return this.native.options();
    }
    setOptions(value: InputDialogOptions): void {
        this.native.setOptions(value);
    }
    textEchoMode(): EchoMode {
        return this.native.textEchoMode();
    }
    setTextEchoMode(value: EchoMode): void {
        this.native.setTextEchoMode(value);
    }
    textValue(): string {
        return this.native.textValue();
    }
    setTextValue(value: string): void {
        this.native.setTextValue(value);
    }
}
wrapperCache.registerWrapper('QInputDialogWrap', QInputDialog);

export interface QInputDialogSignals extends QDialogSignals {
    doubleValueChanged: (value: number) => void;
    doubleValueSelected: (value: number) => void;
    intValueChanged: (value: number) => void;
    intValueSelected: (value: number) => void;
    textValueChanged: (text: string) => void;
    textValueSelected: (text: string) => void;
}

export enum InputMode {
    TextInput = 0,
    IntInput = 1,
    DoubleInput = 2,
}

export enum InputDialogOptions {
    NoButtons = 1,
    UseListViewForComboBoxItems = 2,
    UsePlainTextEditForTextInput = 3,
}
