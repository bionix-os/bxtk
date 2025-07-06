package bxtk.ui;

import bxtk.core.Color;
import bxtk.core.Element;

@:native("ColorRect")
extern class ColorRect extends Control {
    public var color: Color;
    @:native("cast")
    public static function toColorRect(type: Dynamic): ColorRect;
}

abstract ColorRectAbstract(ColorRect) from ColorRect to ColorRect {
    @:from
    public static function fromElement(element: bxtk.core.Element): ColorRectAbstract {
        var rect = ColorRect.toColorRect(element);
        if (rect.isNull()) {
            return null;
        }
        return rect;
    }
}