import { QObject } from "../QtCore/QObject";
import { NativeElement } from "../core/Component";
import { checkIfNativeElement } from "../utils/helpers";
import addon from "../utils/addon";
import { QVariant } from "../QtCore/QVariant";

export class QWebData extends QObject {
  native: NativeElement;
  constructor();
  constructor(arg?: NativeElement | QObject) {
    super(arg?.native);
    if (checkIfNativeElement(arg)) {
      this.native = arg as NativeElement;
    } else if (arg instanceof QObject) {
      this.native = new addon.QWebData(arg.native);
    } else if (!arg) {
      this.native = new addon.QWebData(new QObject().native);
    } else {
      throw new Error(
        "QWebChannel cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  getValue(): QVariant {
    return this.native.value();
  }

  setValue(values: QVariant[]): void {
    this.native.setValue(values);
  }
}
