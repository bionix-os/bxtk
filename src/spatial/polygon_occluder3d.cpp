#include "polygon_occluder3d.h"

void bxtk::spatial::bindPolygonOccluder3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::PolygonOccluder3D>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::PolygonOccluder3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, Occluder3D>(),
        "polygon", sol::property(&PolygonOccluder3D::getPolygon, &PolygonOccluder3D::setPolygon),
        "cast", [](bxtk::core::Resource* instance) {
            return new PolygonOccluder3D(godot::Object::cast_to<GodotPolygonOccluder3D>(instance->getResource()));
        }
    );
}