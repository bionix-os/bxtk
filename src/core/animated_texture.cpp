#include "animated_texture.h"

void bxtk::core::bindAnimatedTexture(sol::state &lua) {
    lua.new_usertype<bxtk::core::AnimatedTexture>("AnimatedTexture",
        "new", sol::factories(
            []() { return new bxtk::core::AnimatedTexture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::Texture2D>(),
        "currentFrame", sol::property(
            &bxtk::core::AnimatedTexture::getCurrentFrame, 
            &bxtk::core::AnimatedTexture::setCurrentFrame
        ),
        "frames", sol::property(
            &bxtk::core::AnimatedTexture::getFrames, 
            &bxtk::core::AnimatedTexture::setFrames
        ),
        "oneShot", sol::property(
            &bxtk::core::AnimatedTexture::getOneShot, 
            &bxtk::core::AnimatedTexture::setOneShot
        ),
        "frames", sol::property(
            &bxtk::core::AnimatedTexture::getFrames, 
            &bxtk::core::AnimatedTexture::setFrames
        ),
        "pause", sol::property(
            &bxtk::core::AnimatedTexture::getPause,
            &bxtk::core::AnimatedTexture::setPause
        ),
        "speedScale", sol::property(
            &bxtk::core::AnimatedTexture::getSpeedScale, 
            &bxtk::core::AnimatedTexture::setSpeedScale
        ),
        "getFrameDuration", &bxtk::core::AnimatedTexture::getFrameDuration,
        "getFrameTexture", &bxtk::core::AnimatedTexture::getFrameTexture,
        "setFrameDuration", &bxtk::core::AnimatedTexture::setFrameDuration,
        "setFrameTexture", &bxtk::core::AnimatedTexture::setFrameTexture,
        "cast", [](Resource* instance) {
            return new AnimatedTexture(godot::Object::cast_to<GodotAnimatedTexture>(instance->getResource()));
        }
    );
}