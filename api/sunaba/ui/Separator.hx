package bxtk.ui;

@:native("Separator")
extern class Separator extends Control {
    @:native("cast")
    public static function toSeparator(obj: Dynamic): bxtk.ui.Separator;
}

abstract SeparatorAbstract(Separator) from Separator to Separator {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.Separator {
        var separator = bxtk.ui.Separator.toSeparator(element);
        if (separator.isNull()) {
            return null;
        }
        return separator;
    }
}