package bxtk.ui;

@:native("VsplitContainer")
extern class VsplitContainer extends SplitContainer {
    @:native("cast")
    public static function toVSplitContainer(obj: Dynamic): bxtk.ui.VsplitContainer;
}

abstract VsplitContainerAbstract(VsplitContainer) from VsplitContainer to VsplitContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.VsplitContainer {
        var vsplitContainer = bxtk.ui.VsplitContainer.toVSplitContainer(element);
        if (vsplitContainer.isNull()) {
            return null;
        }
        return vsplitContainer;
    }
}