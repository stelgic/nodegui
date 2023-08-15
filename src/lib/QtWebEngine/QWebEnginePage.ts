import { Component } from "../core/Component";
import { NativeElement } from "../core/Component";
import { checkIfNativeElement } from "../utils/helpers";
import { QWebChannel } from "./QWebChannel";

export class QWebEnginePage extends Component {
  native: NativeElement;
  constructor(native: NativeElement) {
    super(native);
    if (checkIfNativeElement(native)) {
      this.native = native;
    } else {
      throw new Error(
        "QWebEnginePage cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  runJavaScript(script: string): void {
    this.native.runJavaScript(script);
  }
  setWebChannel(channel: QWebChannel): void {
    this.native.setWebChannel(channel.native);
  }

  webChannel(): QWebChannel {
    return new QWebChannel(this.native.webChannel());
  }
}
