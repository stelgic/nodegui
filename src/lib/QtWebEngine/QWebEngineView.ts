import addon from '../utils/addon';
import { QUrl } from "../QtCore/QUrl";
import { QWidget } from "../QtWidgets/QWidget";
import { QWidgetSignals } from "../QtWidgets/QWidget";
import { wrapperCache } from '../core/WrapperCache';
import { NativeElement } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';

import { QWebEngineSettings } from "./QWebEngineSettings";
import { QWebEnginePage } from "./QWebEnginePage";
import { QAction } from '../QtWidgets/QAction';


export class QWebEngineView extends QWidget<QWebEngineViewSignals> {
  constructor(arg?: QWidget<QWidgetSignals> | NativeElement) {
    let native: NativeElement;
    if (checkIfNativeElement(arg)) {
        native = arg as NativeElement;
    } else if (arg != null) {
        const parent = arg as QWidget;
        native = new addon.QWebEngineView(parent.native);
    } else {
        native = new addon.QWebEngineView();
    }
    super(native);
  }
  load(url: string) {
    this.setProperty("url", url);
  }
  url(): QUrl {
    return QUrl.fromQVariant(this.property("url"));
  }
  settings(): QWebEngineSettings {
    return new QWebEngineSettings(this.native.settings());
  }

  page(): QWebEnginePage {
    return new QWebEnginePage(this.native.page());
  }

  setHtml(html: string, baseUrl: string | null): QWebEnginePage {
    return this.native.setHtml(html, baseUrl);
  }

  setZoomFactor(factor: number) {
    this.native.setZoomFactor(factor);
  }

  reload(): void {
    return this.native.reload();
  }
}

wrapperCache.registerWrapper('QWebEngineViewWrap', QWebEngineView);

export interface QWebEngineViewSignals extends QWidgetSignals {
  loadFinished: (ok: boolean) => void;
  loadProgress: (progress: number) => void;
  loadStarted: () => void;
  selectionChanged: () => void;
  urlChanged: (url: string) => void;
  titleChanged: (title: string) => void;
}


