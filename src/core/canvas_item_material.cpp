#include "canvas_item_material.h"

void sunaba::core::bindCanvasItemMaterial(sol::state_view &lua) {
    lua.new_usertype<CanvasItemMaterial>("CanvasItemMaterial",
        sol::constructors<CanvasItemMaterial()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Material>(),
        "blendMode", sol::property(&CanvasItemMaterial::getBlendMode, &CanvasItemMaterial::setBlendMode),
        "lightMode", sol::property(&CanvasItemMaterial::getLightMode, &CanvasItemMaterial::setLightMode),
        "particlesAnimHFrames", sol::property(&CanvasItemMaterial::getParticlesAnimHFrames, &CanvasItemMaterial::setParticlesAnimHFrames));
}