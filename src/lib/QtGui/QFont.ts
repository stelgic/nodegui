import { Component, NativeElement } from '../core/Component';
import addon from '../utils/addon';
import { QVariant } from '../QtCore/QVariant';
import { checkIfNativeElement } from '../utils/helpers';

export class QFont extends Component {
    constructor();
    constructor(font: QFont);
    constructor(native: NativeElement);
    constructor(family: string, pointSize?: number, weight?: QFontWeight, italic?: boolean);
    constructor(arg?: QFont | string | NativeElement, pointSize = -1, weight = -1, italic = false) {
        let native: NativeElement;
        if (checkIfNativeElement(arg)) {
            native = arg as NativeElement;
        } else if (arg instanceof QFont) {
            native = arg.native;
        } else if (typeof arg === 'string') {
            native = new addon.QFont(arg, pointSize, weight, italic);
        } else {
            native = new addon.QFont();
        }
        super(native);
    }
    bold(): boolean {
        return this.native.bold();
    }
    setBold(enable: boolean): void {
        this.native.setBold(enable);
    }
    setCapitalization(caps: QFontCapitalization): void {
        this.native.setCapitalization(caps);
    }
    capitalization(): QFontCapitalization {
        return this.native.capitalization();
    }
    setFamily(family: string): void {
        this.native.setFamily(family);
    }
    family(): string {
        return this.native.family();
    }
    setPixelSize(value: number): void {
        this.native.setPixelSize(value);
    }
    setPointSize(value: number): void {
        this.native.setPointSize(value);
    }
    pixelSize(): number {
        return this.native.pixelSize();
    }
    pointSize(): number {
        return this.native.pointSize();
    }
    setStretch(factor: QFontStretch): void {
        this.native.setStretch(factor);
    }
    stretch(): QFontStretch {
        return this.native.stretch();
    }
    setWeight(weight: QFontWeight): void {
        this.native.setWeight(weight);
    }
    weight(): QFontWeight {
        return this.native.weight();
    }
    setItalic(enable: boolean): void {
        this.native.setItalic(enable);
    }
    italic(): boolean {
        return this.native.italic();
    }
    setStyleName(style: string): void {
        this.native.setStyleName(style);
    }
    toString(): string {
        return this.native.toString();
    }
    static fromQVariant(variant: QVariant): QFont {
        return new QFont(addon.QFont.fromQVariant(variant.native));
    }
}

export enum QFontStretch {
    AnyStretch = 0,
    UltraCondensed = 50,
    ExtraCondensed = 62,
    Condensed = 75,
    SemiCondensed = 87,
    Unstretched = 100,
    SemiExpanded = 112,
    Expanded = 125,
    ExtraExpanded = 150,
    UltraExpanded = 200,
}
export enum QFontCapitalization {
    MixedCase = 0,
    AllUppercase = 1,
    AllLowercase = 2,
    SmallCaps = 3,
    Capitalize = 4,
}
export enum QFontWeight {
    Thin = 100,
    ExtraLight = 200,
    Light = 300,
    Normal = 400,
    Medium = 500,
    DemiBold = 600,
    Bold = 700,
    ExtraBold = 800,
    Black = 900,
}
