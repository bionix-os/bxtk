package bxtk.spatial;

import bxtk.core.Component;

@:native("IVisualInstance")
extern class IVisualInstance extends Component {
    public var layerMask : Int;
    public var sortingOffset : Float;
    public var sortingUseAabbCenter : Bool;
    public function getLayerMaskValue(layer : Int) : Bool;
    public function setLayerMaskValue(layer : Int, value : Bool) : Void;
}