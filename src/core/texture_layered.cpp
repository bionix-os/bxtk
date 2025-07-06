#include "texture_layered.h"

void bxtk::core::bindTextureLayered(sol::state &lua) {
    lua.new_usertype<bxtk::core::TextureLayered>("TextureLayered",
        "new", sol::factories(
            []() { return new bxtk::core::TextureLayered(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture>(),
        "getFormat", &bxtk::core::TextureLayered::getFormat,
        "getHeight", &bxtk::core::TextureLayered::getHeight,
        "getLayerData", &bxtk::core::TextureLayered::getLayerData,
        "getLayeredType", &bxtk::core::TextureLayered::getLayeredType,
        "getLayers", &bxtk::core::TextureLayered::getLayers,
        "getWidth", &bxtk::core::TextureLayered::getWidth,
        "cast", [](Resource* instance) {
            return new TextureLayered(godot::Object::cast_to<GodotTextureLayered>(instance->getResource()));
        }
    );
}