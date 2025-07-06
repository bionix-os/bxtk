#include "placeholder_texture2d_array.h"

void bxtk::core::bindPlaceholderTexture2DArray(sol::state &lua) {
    lua.new_usertype<bxtk::core::PlaceholderTexture2DArray>("PlaceholderTexture2DArray",
        "new", sol::factories(
            []() { return new bxtk::core::PlaceholderTexture2DArray(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered, bxtk::core::PlaceholderTextureLayered>(),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2DArray(godot::Object::cast_to<GodotPlaceholderTexture2DArray>(instance->getResource()));
        }
    );
}