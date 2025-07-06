package bxtk.ui;

@:native("HscrollBar")
extern class HscrollBar extends ScrollBar {
    @:native("cast")
    public static function toHScrollBar(obj: Dynamic): bxtk.ui.HscrollBar;
}

abstract HscrollBarAbstract(HscrollBar) from HscrollBar to HscrollBar {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.HscrollBar {
        var hScrollBar = bxtk.ui.HscrollBar.toHScrollBar(element);
        if (hScrollBar.isNull()) {
            return null;
        }
        return hScrollBar;
    }
}