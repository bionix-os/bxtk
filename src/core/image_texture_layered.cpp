#include "image_texture_layered.h"

void bxtk::core::bindImageTextureLayered(sol::state_view& lua) {
    lua.new_usertype<bxtk::core::ImageTextureLayered>("ImageTextureLayered",
        "new", sol::factories(
            []() { return new bxtk::core::ImageTextureLayered(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered>(),
        "createFromImages", &ImageTextureLayered::createFromImages,
        "updateLayer", &ImageTextureLayered::updateLayer,
        "cast", [](bxtk::core::Resource* instance) {
            return new ImageTextureLayered(godot::Object::cast_to<GodotImageTextureLayered>(instance->getResource()));
        }
    );
}