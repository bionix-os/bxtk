package bxtk.ui;

import bxtk.core.Event;

@:native("ScrollBar")
extern class ScrollBar extends Range {
    public var customStep: Float;
    public var scrolling: Event;
    @:native("cast")
    public static function toScrollBar(obj: Dynamic): bxtk.ui.ScrollBar;
}

abstract ScrollBarAbstract(ScrollBar) from ScrollBar to ScrollBar {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.ScrollBar {
        var scrollBar = bxtk.ui.ScrollBar.toScrollBar(element);
        if (scrollBar.isNull()) {
            return null;
        }
        return scrollBar;
    }
}