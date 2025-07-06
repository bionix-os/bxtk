#include "placeholder_texture_layered.h"

void bxtk::core::bindPlaceholderTextureLayered(sol::state &lua) {
    lua.new_usertype<bxtk::core::PlaceholderTextureLayered>("PlaceholderTextureLayered",
        "new", sol::factories(
            []() { return new bxtk::core::PlaceholderTextureLayered(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered>(),
        "layers", sol::property(
            &bxtk::core::PlaceholderTextureLayered::getLayers,
            &bxtk::core::PlaceholderTextureLayered::setLayers
        ),
        "size", sol::property(
            &bxtk::core::PlaceholderTextureLayered::getSize,
            &bxtk::core::PlaceholderTextureLayered::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTextureLayered(godot::Object::cast_to<GodotPlaceholderTextureLayered>(instance->getResource()));
        }
    );
}