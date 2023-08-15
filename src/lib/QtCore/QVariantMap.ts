import { NativeElement, Component } from '../core/Component';
import { QVariant } from './QVariant';
import addon from '../utils/addon';
import { checkIfNativeElement } from '../utils/helpers';
import { QObject } from './QObject';

export class QVariantMap extends Component {
    constructor();
    constructor(nativeElement: NativeElement);
    constructor(variant: QVariantMap);
    constructor(arg?: QVariantMap | NativeElement) {
        let native: NativeElement;
        if (checkIfNativeElement(arg) && arg instanceof addon.QVariantMap) {
            native = arg as NativeElement;
        } else if(arg) {
            native = new addon.QVariantMap(arg.native);
        } else {
            native = new addon.QVariantMap();
        }
        super(native);
    }
    isEmpty(): string {
        return this.native.isEmpty();
    }
    size(): number {
        return this.native.size();
    }
    find(key: string): QVariant {
        return this.native.find(key);
    }
    insert(key: string, value: QVariant): void {
        return this.native.insert(key, value);
    }
    erase(key: string): void[] {
        return this.native.erase(key);
    }
    count(key: string): number {
        return this.native.count(key);
    }
    keys(): string[] {
        return this.native.keys();
    }
    values(): QVariant[] {
        return this.native.values();
    }
    toQVariant(): QVariant {
        return this.native.toQVariant();
    }
}

