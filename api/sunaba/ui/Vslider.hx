package bxtk.ui;

@:native("Vslider")
extern class Vslider extends Slider {
    @:native("cast")
    public static function toVSlider(obj: Dynamic): bxtk.ui.Vslider;
}

abstract VsliderAbstract(Vslider) from Vslider to Vslider {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.Vslider {
        var vSlider = bxtk.ui.Vslider.toVSlider(element);
        if (vSlider.isNull()) {
            return null;
        }
        return vSlider;
    }
}