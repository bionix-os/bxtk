#include "standard_material3d.h"

void bxtk::spatial::bindStandardMaterial3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::StandardMaterial3D>("StandardMaterial3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::StandardMaterial3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Material, bxtk::spatial::BaseMaterial3D>(),
        "cast", [](bxtk::core::Resource* instance) {
            return new StandardMaterial3D(godot::Object::cast_to<GodotStandardMaterial3D>(instance->getResource()));
        }
    );
}