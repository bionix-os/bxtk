#include "texture3d.h"

void bxtk::spatial::bindTexture3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::Texture3D>("Texture3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::Texture3D(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Texture>(),
        "createPlaceholder", &Texture3D::createPlaceholder,
        "getData", &Texture3D::getData,
        "getDepth", &Texture3D::getDepth,
        "getFormat", &Texture3D::getFormat,
        "getHeight", &Texture3D::getHeight,
        "getWidth", &Texture3D::getWidth,
        "hasMipmaps", &Texture3D::hasMipmaps,
        "cast", [](bxtk::core::Resource* instance) {
            return new Texture3D(godot::Object::cast_to<GodotTexture3D>(instance->getResource()));
        }
    );
}