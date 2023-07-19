import { Component } from "../core/Component";
import { NativeElement } from "../core/Component";
import { checkIfNativeElement } from "../utils/helpers";

export class QWebEngineSettings extends Component {
  native: NativeElement;
  constructor(native: NativeElement) {
    super(native);
    if (checkIfNativeElement(native)) {
      this.native = native;
    } else {
      throw new Error(
        "QWebEngineSettings cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  setUnknownUrlSchemePolicy(policy: UnknownUrlSchemePolicy): void {
    this.native.setUnknownUrlSchemePolicy(policy);
  }
}

export enum UnknownUrlSchemePolicy {
  DisallowUnknownUrlSchemes = 1,
  AllowUnknownUrlSchemesFromUserInteraction,
  AllowAllUnknownUrlSchemes
}
