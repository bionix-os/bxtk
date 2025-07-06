#include "occluder3d.h"

void bxtk::spatial::bindOccluder3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::Occluder3D>("Occluder3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::Occluder3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "getIndices", &Occluder3D::getIndices,
        "getVertices", &Occluder3D::getVertices,
        "cast", [](bxtk::core::Resource* instance) {
            return new Occluder3D(godot::Object::cast_to<GodotOccluder3D>(instance->getResource()));
        }
    );
}