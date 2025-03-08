#include "material.h"

void sunaba::core::bindMaterial(sol::state_view& lua) {
    lua.new_usertype<Material>("Material",
        sol::constructors<Material(), Material(GodotMaterial*)>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "nextPass", sol::property(&Material::getNextPass, &Material::setNextPass),
        "renderPriority", sol::property(&Material::getRenderPriority, &Material::setRenderPriority),
        "createPlaceholder", &Material::createPlaceholder
    );
}