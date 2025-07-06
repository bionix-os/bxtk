package bxtk.ui;

import bxtk.core.Color;

@:native("ReferenceRect")
extern class ReferenceRect extends Control {
    public var borderColor: Color;
    public var borderWidth: Float;
    @:native("cast")
    public static function toReferenceRect(obj: Dynamic): bxtk.ui.ReferenceRect;
}

abstract ReferenceRectAbstract(ReferenceRect) from ReferenceRect to ReferenceRect {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.ReferenceRect {
        var referenceRect = bxtk.ui.ReferenceRect.toReferenceRect(element);
        if (referenceRect.isNull()) {
            return null;
        }
        return referenceRect;
    }
}