package bxtk.desktop;

import bxtk.core.Event;

@:native("Popup")
extern class Popup extends Window {
    public var popupHide: Event;
    @:native("cast")
    public static function toPopup(type: Dynamic): Popup;
}

abstract PopupAbstract(Popup) from Popup to Popup {
    @:from
    public static function fromElement(element: bxtk.core.Element): PopupAbstract {
        var popup = Popup.toPopup(element);
        if (popup.isNull()) {
            return null;
        }
        return popup;
    }
}