#include "sphere_occluder3d.h"

void bxtk::spatial::bindSphereOccluder3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::SphereOccluder3D>("SphereOccluder3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::SphereOccluder3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::spatial::Occluder3D>(),
        "radius", sol::property(&SphereOccluder3D::getRadius, &SphereOccluder3D::setRadius),
        "cast", [](bxtk::core::Resource* instance) {
            return new SphereOccluder3D(godot::Object::cast_to<GodotSphereOccluder3D>(instance->getResource()));
        }
    );
}