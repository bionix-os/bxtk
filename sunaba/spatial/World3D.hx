package sunaba.spatial;

import sunaba.core.Resource;
import sunaba.core.Environment;

@:native("World3D")
extern class World3D extends Resource {
    public var cameraAttributes: CameraAttributes;
    public var environment: Environment;
    @:native("cast")
    public function castFrom(res: Dynamic): World3D;
}

abstract World3DAbstract(World3D) from World3D to World3D {
    @:from
    public static function fromResource(resource: Resource): World3DAbstract {
        var world3D = World3D.castFrom(resource);
        if (world3D.isNull()) {
            return null;
        }
        return world3D;
    }
} // end package sunaba.spatial