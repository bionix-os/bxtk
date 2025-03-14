#include "polygon_occluder3d.h"

void sunaba::spatial::bindPolygonOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::PolygonOccluder3D>("ArrayOccluder3D",
        sol::constructors<PolygonOccluder3D()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, Occluder3D>(),
        "polygon", sol::property(&PolygonOccluder3D::getPolygon, &PolygonOccluder3D::setPolygon),
        "cast", [](sunaba::core::Resource* instance) {
            return new PolygonOccluder3D(godot::Object::cast_to<GodotPolygonOccluder3D>(instance->getResource()));
        }
    );
}