package bxtk.ui;

@:native("Hslider")
extern class Hslider extends Slider {
    @:native("cast")
    public static function toHSlider(obj: Dynamic): bxtk.ui.Hslider;
}

abstract HsliderAbstract(Hslider) from Hslider to Hslider {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.Hslider {
        var hSlider = bxtk.ui.Hslider.toHSlider(element);
        if (hSlider.isNull()) {
            return null;
        }
        return hSlider;
    }
}