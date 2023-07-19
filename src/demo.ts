import { QMainWindow } from './lib/QtWidgets/QMainWindow';
import { QLabel } from './lib/QtWidgets/QLabel';
import { FlexLayout } from './lib/core/FlexLayout';
import { QPushButton } from './lib/QtWidgets/QPushButton';
import { QWidget } from './lib/QtWidgets/QWidget';
import { QWebEngineView } from "./lib/QtWebEngine/QWebEngineView";
import { QWebChannel } from "./lib/QtWebEngine/QWebChannel";

const win = new QMainWindow();
win.setWindowTitle('Hello World');

const centralWidget = new QWidget();
centralWidget.setObjectName('myroot');
const rootLayout = new FlexLayout();
centralWidget.setLayout(rootLayout);

const label = new QLabel();
label.setObjectName('mylabel');
label.setText('Hello');

const button = new QPushButton();
button.setText('Hello');
const label2 = new QLabel();
label2.setText('World');
label2.setInlineStyle(`
  color: red;
`);

const webview = new QWebEngineView();
webview.setInlineStyle("align-self:'stretch';");
webview.load("http://google.com");
webview.addEventListener("urlChanged", (url: string) => {
  console.log("changed to", url);
});
webview.addEventListener("selectionChanged", () => {
  console.log("selection", webview.property("selectedText").toString());
});
webview.addEventListener("loadFinished", () => {
  const js = `alert('nodeui');`;
  const page = webview.page();
  page.runJavaScript(js);
});

const channel = new QWebChannel();
webview.page().setWebChannel(channel);

rootLayout.addWidget(label);
rootLayout.addWidget(button);
rootLayout.addWidget(label2);
rootLayout.addWidget(webview);
win.setCentralWidget(centralWidget);
win.setStyleSheet(
    `
    #myroot {
      background-color: #009688;
      height: '100%';
      align-items: 'center';
      justify-content: 'center';
    }
    #mylabel {
      font-size: 16px;
      font-weight: bold;
      padding: 1;
    }
  `,
);
win.show();

(global as any).win = win;
