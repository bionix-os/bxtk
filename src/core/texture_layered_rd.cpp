#include "texture_layered_rd.h"

void bxtk::core::bindTextureLayeredRD(sol::state &lua) {
    lua.new_usertype<bxtk::core::TextureLayeredRD>("TextureLayeredRD",
        "new", sol::factories(
            []() { return new bxtk::core::TextureLayeredRD(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered>(),
        "cast", [](Resource* instance) {
            return new TextureLayeredRD(godot::Object::cast_to<GodotTextureLayeredRD>(instance->getResource()));
        }
    );
}