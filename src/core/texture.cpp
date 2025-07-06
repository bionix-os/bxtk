#include "texture.h"

void bxtk::core::bindTexture(sol::state &lua) {
    lua.new_usertype<bxtk::core::Texture>("Texture",
        "new", sol::factories(
            []() { return new bxtk::core::Texture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "cast", [](Resource* instance) {
            return new Texture(godot::Object::cast_to<GodotTexture>(instance->getResource()));
        }
    );
}