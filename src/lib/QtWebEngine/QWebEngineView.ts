import { QUrl } from "../QtCore/QUrl";
import { QWidget } from "../QtWidgets/QWidget";
import { QWidgetSignals } from "../QtWidgets/QWidget";
import { wrapperCache } from '../core/WrapperCache';
import addon from "../utils/addon";

import { QWebEngineSettings } from "./QWebEngineSettings";
import { QWebEnginePage } from "./QWebEnginePage";


export class QWebEngineView extends QWidget<QWebEngineViewSignals> {
  constructor(parent?: QWidget<any>) {
    let native;
    if (parent != null) {
        native = new addon.QWebEngineView(parent.native);
    } else {
      native = new addon.QWebEngineView();
    }
    
    super(native);
    this.native = native;
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

  setHtml(html: string): QWebEnginePage {
    return this.native.setHtml(html);
  }
}

export interface QWebEngineViewSignals extends QWidgetSignals {
  loadFinished: (ok: boolean) => void;
  loadProgress: (progress: number) => void;
  loadStarted: () => void;
  selectionChanged: () => void;
  urlChanged: (url: string) => void;
  titleChanged: (title: string) => void;
}

wrapperCache.registerWrapper('QWebEngineViewWrap', QWebEngineView);

