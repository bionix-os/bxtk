package bxtk.spatial.mesh;

import bxtk.core.Vector3;
import bxtk.core.Component;

@:native("Box")
extern class Box extends Component {
    public var size : Vector3;
    public var subdivideDepth : Int;
    public var subdivideWidth : Int;
    public var subdivideHeight : Int;
    public static function getFromEntity(entity : bxtk.core.Entity) : Box;
}