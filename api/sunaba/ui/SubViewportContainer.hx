package bxtk.ui;

import bxtk.input.InputEvent;

@:native("SubViewportContainer")
extern class SubViewportContainer extends Container {
    public var mouseTarget: Bool;
    public var stretch: Bool;
    public var stretchShrink: Bool;
    @:native("cast")
    public static function toSubViewportContainer(obj: Dynamic): bxtk.ui.SubViewportContainer;
}

abstract SubViewportContainerAbstract(SubViewportContainer) from SubViewportContainer to SubViewportContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.SubViewportContainer {
        var subViewportContainer = bxtk.ui.SubViewportContainer.toSubViewportContainer(element);
        if (subViewportContainer.isNull()) {
            return null;
        }
        return subViewportContainer;
    }
}