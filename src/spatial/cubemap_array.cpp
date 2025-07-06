#include "cubemap_array.h"

void bxtk::spatial::bindCubemapArray(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::CubemapArray>("CubemapArray",
        "new", sol::factories(
            []() { return new bxtk::spatial::CubemapArray(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered, bxtk::core::ImageTextureLayered>(),
        "createPlaceholder", &CubemapArray::createPlaceholder,
        "cast", [](bxtk::core::Resource* instance) {
            return new CubemapArray(godot::Object::cast_to<GodotCubemapArray>(instance->getResource()));
        }
    );
}