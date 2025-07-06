package bxtk.ui;

@:native("Hseparator")
extern class Hseparator extends Separator {
    @:native("cast")
    public static function toHSeparator(obj: Dynamic): bxtk.ui.Hseparator;
}

abstract HseparatorAbstract(Hseparator) from Hseparator to Hseparator {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.Hseparator {
        var hSeparator = bxtk.ui.Hseparator.toHSeparator(element);
        if (hSeparator.isNull()) {
            return null;
        }
        return hSeparator;
    }
}