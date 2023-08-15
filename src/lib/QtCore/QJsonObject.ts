import { NativeElement, Component } from '../core/Component';
import addon from '../utils/addon';
import { checkIfNativeElement } from '../utils/helpers';
import { QJsonValue } from './QJsonValue';
import { QVariant } from './QVariant';

export class QJsonObject extends Component {
    native: NativeElement;
    constructor();
    constructor(arg?: any | NativeElement) {
        super(arg?.native);
        if (checkIfNativeElement(arg) && arg instanceof addon.QJsonObject) {
            this.native = arg as NativeElement;
        } else if (arg) {
            this.native = new addon.QJsonObject.fromVariantMap(arg);
        } else {
           this.native = new addon.QJsonObject();
        }
    }
    toString(): string {
        return this.native.toString();
    }
    toVariantMap(): string {
        return this.native.toVariantMap();
    }
    value(key: string): QJsonValue {
        return this.native.value(key);
    }
    addStringValue(key: string, value: string) {
        this.native.addStringValue(key, value);
    }
    addIntValue(key: string, value: number) {
        this.native.addIntValue(key, value);
    }
    addBoolValue(key: string, value: boolean) {
        this.native.addBoolValue(key, value);
    }
    addValue(key: string, value: QVariant) {
        this.native.addValue(key, value);
    }
}

