#include "placeholder_texture2d.h"

void bxtk::core::bindPlaceholderTexture2D(sol::state &lua) {
    lua.new_usertype<bxtk::core::PlaceholderTexture2D>("PlaceholderTexture2D",
        "new", sol::factories(
            []() { return new bxtk::core::PlaceholderTexture2D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::Texture2D>(),
        "size", sol::property(
            &bxtk::core::PlaceholderTexture2D::getSize, 
            &bxtk::core::PlaceholderTexture2D::setSize
        ),
        "cast", [](Resource* instance) {
            return new PlaceholderTexture2D(godot::Object::cast_to<GodotPlaceholderTexture2D>(instance->getResource()));
        }
    );
}