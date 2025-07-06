#include "texture_cubemap_rd.h"

void bxtk::core::bindTextureCubemapRD(sol::state &lua) {
    lua.new_usertype<bxtk::core::TextureCubemapRD>("TextureCubemapRD",
        "new", sol::factories(
            []() { return new bxtk::core::TextureCubemapRD(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered, bxtk::core::TextureLayeredRD>(),
        "cast", [](bxtk::core::Resource* instance) {
            return new TextureCubemapRD(godot::Object::cast_to<GodotTextureCubemapRD>(instance->getResource()));
        }
    );
}