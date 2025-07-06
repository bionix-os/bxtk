#include "texture2d.h"

void bxtk::core::bindTexture2D(sol::state &lua) {
    lua.new_usertype<bxtk::core::Texture2D>("Texture2D",
        "new", sol::factories(
            []() { return new bxtk::core::Texture2D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture>(),
        "createPlaceholder", &bxtk::core::Texture2D::createPlaceholder,
        "getHeight", &bxtk::core::Texture2D::getHeight,
        "getImage", &bxtk::core::Texture2D::getImage,
        "getSize", &bxtk::core::Texture2D::getSize,
        "getWidth", &bxtk::core::Texture2D::getWidth,
        "hasAlpha", &bxtk::core::Texture2D::hasAlpha,
        "cast", [](Resource* instance) {
            return new Texture2D(godot::Object::cast_to<GodotTexture2D>(instance->getResource()));
        }
    );
}