package bxtk.ui;

import bxtk.core.Element;

@:native("CenterContainer")
extern class CenterContainer extends Container {
    public function new();
    public var useTopLeft: Bool;
    @:native("cast")
    public static function toCenterContainer(type: Dynamic): CenterContainer;
}

abstract CenterContainerAbstract(CenterContainer) from CenterContainer to CenterContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): CenterContainerAbstract {
        var container = CenterContainer.toCenterContainer(element);
        if (container.isNull()) {
            return null;
        }
        return container;
    }
}