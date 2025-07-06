package bxtk.ui;

@:native("Vseparator")
extern class Vseparator extends Control {
    @:native("cast")
    public static function toVSeparator(obj: Dynamic): bxtk.ui.Vseparator;
}

abstract VseparatorAbstract(Vseparator) from Vseparator to Vseparator {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.Vseparator {
        var vSeparator = bxtk.ui.Vseparator.toVSeparator(element);
        if (vSeparator.isNull()) {
            return null;
        }
        return vSeparator;
    }
}