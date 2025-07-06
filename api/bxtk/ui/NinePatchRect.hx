package bxtk.ui;

import bxtk.core.Rect2;
import bxtk.core.Texture2D;

@:native("NinePatchRect")
extern class NinePatchRect extends Control {
    public var axisStretchHorizontal: Int;
    public var axisStretchVertical: Int;
    public var drawCenter: Bool;
    public var patchMarginBottom: Int;
    public var patchMarginLeft: Int;
    public var patchMarginRight: Int;
    public var patchMarginTop: Int;
    public var regionRect: Rect2;
    public var texture: Texture2D;
    public var textureChanged: bxtk.core.Event;
    public function getPatchMargin(side: Int): Int;
    public function setPatchMargin(side: Int, margin: Int): Void;
    @:native("cast")
    public static function toNinePatchRect(obj: Dynamic): bxtk.ui.NinePatchRect;
}

abstract NinePatchRectAbstract(NinePatchRect) from NinePatchRect to NinePatchRect {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.NinePatchRect {
        var ninePatchRect = bxtk.ui.NinePatchRect.toNinePatchRect(element);
        if (ninePatchRect.isNull()) {
            return null;
        }
        return ninePatchRect;
    }
}