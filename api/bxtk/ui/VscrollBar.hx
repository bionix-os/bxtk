package bxtk.ui;

@:native("VscrollBar")
extern class VscrollBar extends ScrollBar {
    @:native("cast")
    public static function toVScrollBar(obj: Dynamic): bxtk.ui.VscrollBar;
}

abstract VscrollBarAbstract(VscrollBar) from VscrollBar to VscrollBar {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.VscrollBar {
        var vScrollBar = bxtk.ui.VscrollBar.toVScrollBar(element);
        if (vScrollBar.isNull()) {
            return null;
        }
        return vScrollBar;
    }
}