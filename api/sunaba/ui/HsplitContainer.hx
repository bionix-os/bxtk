package bxtk.ui;

@:native("HsplitContainer")
extern class HsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toHSplitContainer(obj: Dynamic): bxtk.ui.HsplitContainer;
}

abstract HsplitContainerAbstract(HsplitContainer) from HsplitContainer to HsplitContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.HsplitContainer {
        var hsplitContainer = bxtk.ui.HsplitContainer.toHSplitContainer(element);
        if (hsplitContainer.isNull()) {
            return null;
        }
        return hsplitContainer;
    }
}