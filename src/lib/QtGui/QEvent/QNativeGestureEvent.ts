import addon from '../../utils/addon';
import { NativeRawPointer } from '../../core/Component';
import { NativeGestureType } from '../../QtEnums';
import { QInputEvent } from './QInputEvent';

export class QNativeGestureEvent extends QInputEvent {
    constructor(event: NativeRawPointer<'QEvent'>) {
        super(new addon.QNativeGestureEvent(event));
    }

    //Needs QTouchDevice to implement this
    // device(): QTouchDevice {
    //     return undefined;
    // }
    /** Returns the gesture type */
    gestureType(): NativeGestureType {
        return this.native.gestureType();
    }
    /**
     * Returns the position of the gesture as a QPointF in screen coordinates
     */
    globalPos(): { x: number; y: number } {
        return this.native.globalPos();
    }
    /**
     * Returns the position of the gesture as a QPointF,
     * relative to the widget or item that received the event
     */
    localPos(): { x: number; y: number } {
        return this.native.localPos();
    }
    /**
     * Returns the position of the mouse cursor,
     * relative to the widget or item that received the event
     */
    pos(): { x: number; y: number } {
        return this.native.pos();
    }
    /**
     * Returns the position of the gesture as a QPointF in screen coordinates
     */
    screenPos(): { x: number; y: number } {
        return this.native.screenPos();
    }
    /**
     * Returns the position of the gesture as a QPointF,
     * relative to the window that received the event.
     */
    windowPos(): { x: number; y: number } {
        return this.native.windowPos();
    }
    /**
     * Returns the gesture value.
     *
     * The value should be interpreted based on the gesture type.
     * For example, a Zoom gesture provides a scale factor while a
     * Rotate gesture provides a rotation delta.
     */
    value(): number {
        return this.native.value();
    }
}
