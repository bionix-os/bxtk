package bxtk.ui;

@:native("PanelContainer")
extern class PanelContainer extends Container {
    @:native("cast")
    public static function toPanelContainer(obj: Dynamic): bxtk.ui.PanelContainer;
}

abstract PanelContainerAbstract(PanelContainer) from PanelContainer to PanelContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.PanelContainer {
        var panelContainer = bxtk.ui.PanelContainer.toPanelContainer(element);
        if (panelContainer.isNull()) {
            return null;
        }
        return panelContainer;
    }
}