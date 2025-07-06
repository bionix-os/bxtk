#include "image_texture.h"

void bxtk::core::bindImageTexture(sol::state &lua) {
    lua.new_usertype<bxtk::core::ImageTexture>("ImageTexture",
        "new", sol::factories(
            []() { return new bxtk::core::ImageTexture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::Texture2D>(),
        "image", sol::property(
            &bxtk::core::ImageTexture::getImage, 
            &bxtk::core::ImageTexture::setImage
        ),
        "createFromImage", &bxtk::core::ImageTexture::createFromImage,
        "getFormat", &bxtk::core::ImageTexture::getFormat,
        "cast", [](Resource* instance) {
            return new ImageTexture(godot::Object::cast_to<GodotImageTexture>(instance->getResource()));
        }
    );
}