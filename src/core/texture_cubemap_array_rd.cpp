#include "texture_cubemap_array_rd.h"

void bxtk::core::bindTextureCubemapArrayRD(sol::state &lua) {
    lua.new_usertype<bxtk::core::TextureCubemapArrayRD>("TextureCubemapArrayRD",
        "new", sol::factories(
            []() { return new bxtk::core::TextureCubemapArrayRD(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered, bxtk::core::TextureLayeredRD>(),
        "cast", [](bxtk::core::Resource* instance) {
            return new TextureCubemapArrayRD(godot::Object::cast_to<GodotTextureCubemapArrayRD>(instance->getResource()));
        }
    );
}