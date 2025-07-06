#include "texture3drd.h"

void bxtk::spatial::bindTexture3DRD(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::Texture3DRD>("Texture3DRD",
        "new", sol::factories(
            []() { return new bxtk::spatial::Texture3DRD(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, Texture3D>(),
        "cast", [](bxtk::core::Resource* instance) {
            return new Texture3DRD(godot::Object::cast_to<GodotTexture3DRD>(instance->getResource()));
        }
    );
}