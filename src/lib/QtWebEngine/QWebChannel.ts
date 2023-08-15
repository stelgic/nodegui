import { QObject } from "../QtCore/QObject";
import { Component } from "../core/Component";
import { NativeElement } from "../core/Component";
import { checkIfNativeElement } from "../utils/helpers";
import addon from "../utils/addon";

export class QWebChannel extends Component {
  native: NativeElement;
  constructor(arg?: NativeElement | QObject) {
    super(arg?.native);
    if (checkIfNativeElement(arg)) {
      this.native = arg as NativeElement;
    } else if (arg instanceof QObject) {
      this.native = new addon.QWebChannel(arg.native);
    } else if (!arg) {
      this.native = new addon.QWebChannel(new QObject().native);
    } else {
      throw new Error(
        "QWebChannel cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  registerObject(name: string, obj: QObject): void {
    this.native.registerObject(name, obj.native);
  }

  deregisterObject(obj: QObject): void {
    this.native.deregisterObject(obj.native);
  }
}
