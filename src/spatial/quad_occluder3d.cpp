#include "quad_occluder3d.h"

void bxtk::spatial::bindQuadOccluder3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::QuadOccluder3D>("QuadOccluder3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::QuadOccluder3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, Occluder3D>(),
        "size", sol::property(&QuadOccluder3D::getSize, &QuadOccluder3D::setSize),
        "cast", [](bxtk::core::Resource* instance) {
            return new QuadOccluder3D(godot::Object::cast_to<GodotQuadOccluder3D>(instance->getResource()));
        }
    );
}