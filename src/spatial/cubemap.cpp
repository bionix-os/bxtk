#include "cubemap.h"

void bxtk::spatial::bindCubemap(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::Cubemap>("Cubemap",
        "new", sol::factories(
            []() { return new bxtk::spatial::Cubemap(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture, bxtk::core::TextureLayered, bxtk::core::ImageTextureLayered>(),
        "createPlaceholder", &Cubemap::createPlaceholder,
        "cast", [](bxtk::core::Resource* instance) {
            return new Cubemap(godot::Object::cast_to<GodotCubemap>(instance->getResource()));
        }
    );
}