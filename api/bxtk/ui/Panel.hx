package bxtk.ui;

@:native("Panel")
extern class Panel extends Control {
    @:native("cast")
    public static function toPanel(obj: Dynamic): bxtk.ui.Panel;
}

abstract PanelAbstract(Panel) from Panel to Panel {
    @:from
    public static function fromElement(element: bxtk.core.Element): PanelAbstract {
        var panel = bxtk.ui.Panel.toPanel(element);
        if (panel.isNull()) {
            return null;
        }
        return panel;
    }
}