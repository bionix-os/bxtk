#include "orm_material3d.h"

void bxtk::spatial::bindOrmMaterial3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::OrmMaterial3D>("OrmMaterial3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::OrmMaterial3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Material, bxtk::spatial::BaseMaterial3D>(),
        "cast", [](bxtk::core::Resource* instance) {
            return new OrmMaterial3D(godot::Object::cast_to<GodotOrmMaterial3D>(instance->getResource()));
        }
    );
}