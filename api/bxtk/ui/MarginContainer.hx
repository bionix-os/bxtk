package bxtk.ui;

@:native("MarginContainer")
extern class MarginContainer extends Container {
    @:native("cast")
    public static function toMarginContainer(obj: Dynamic): bxtk.ui.MarginContainer;
}

abstract MarginContainerAbstract(MarginContainer) from MarginContainer to MarginContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.MarginContainer {
        var marginContainer = bxtk.ui.MarginContainer.toMarginContainer(element);
        if (marginContainer.isNull()) {
            return null;
        }
        return marginContainer;
    }
}