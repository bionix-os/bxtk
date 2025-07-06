#include "panorama_sky_material.h"

void bxtk::spatial::bindPanoramaSkyMaterial(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::PanoramaSkyMaterial>("PanoramaSkyMaterial",
        "new", sol::factories(
            []() { return new bxtk::spatial::PanoramaSkyMaterial(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Material>(),
        "energyMultiplier", sol::property(&PanoramaSkyMaterial::getEnergyMultiplier, &PanoramaSkyMaterial::setEnergyMultiplier),
        "filterEnabled", sol::property(&PanoramaSkyMaterial::getFilterEnabled, &PanoramaSkyMaterial::setFilterEnabled),
        "panorama", sol::property(&PanoramaSkyMaterial::getPanorama, &PanoramaSkyMaterial::setPanorama),
        "cast", [](bxtk::core::Resource* instance) {
            return new PanoramaSkyMaterial(godot::Object::cast_to<GodotPanoramaSkyMaterial>(instance->getResource()));
        }
    );
}