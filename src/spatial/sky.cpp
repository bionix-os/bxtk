#include "sky.h"

void bxtk::spatial::bindSky(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::Sky>("Sky",
        "new", sol::factories(
            []() { return new bxtk::spatial::Sky(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "processMode", sol::property(&Sky::getProcessMode, &Sky::setProcessMode),
        "radianceSize", sol::property(&Sky::getRadianceSize, &Sky::setRadianceSize),
        "skyMaterial", sol::property(&Sky::getSkyMaterial, &Sky::setSkyMaterial),
        "cast", [](bxtk::core::Resource* instance) {
            return new Sky(godot::Object::cast_to<GodotSky>(instance->getResource()));
        }
    );
}