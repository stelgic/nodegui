import { NativeElement, Component } from '../core/Component';
import addon from '../utils/addon';
import { checkIfNativeElement } from '../utils/helpers';
import { QJsonObject } from './QJsonObject';
import { QVariant } from './QVariant';

export class QJsonValue extends Component {
    constructor();
    constructor(arg?: any | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg) && arg instanceof addon.QJsonValue) {
            native = arg as NativeElement;
        } else if (arg) {
            native = new addon.QJsonValue.fromVariantMap(arg);
        } else {
            native = new addon.QJsonValue();
        }
        super(native);
    }
    toObject(): QJsonObject {
        return this.native.toObject();
    }
    toVariant(): QVariant {
        return this.native.toVariant();
    }
}

