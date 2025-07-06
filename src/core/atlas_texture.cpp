#include "atlas_texture.h"

void bxtk::core::bindAtlasTexture(sol::state &lua) {
    lua.new_usertype<bxtk::core::AtlasTexture>("AtlasTexture",
        "new", sol::factories(
            []() { return new bxtk::core::AtlasTexture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::Texture2D>(),
        "atlas", sol::property(
            &bxtk::core::AtlasTexture::getAtlas, 
            &bxtk::core::AtlasTexture::setAtlas
        ),
        "filterClip", sol::property(
            &bxtk::core::AtlasTexture::getFilterClip, 
            &bxtk::core::AtlasTexture::setFilterClip
        ),
        "margin", sol::property(
            &bxtk::core::AtlasTexture::getMargin, 
            &bxtk::core::AtlasTexture::setMargin
        ),
        "region", sol::property(
            &bxtk::core::AtlasTexture::getRegion, 
            &bxtk::core::AtlasTexture::setRegion
        ),
        "cast", [](Resource* instance) {
            return new AtlasTexture(godot::Object::cast_to<GodotAtlasTexture>(instance->getResource()));
        }
    );
}