#include "camera_attributes.h"

void bxtk::spatial::bindCameraAttributes(sol::state_view& lua) {
    lua.new_usertype<CameraAttributes>("CameraAttributes",
        "new", sol::factories(
            []() { return new CameraAttributes(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "autoExposureEnabled", sol::property(&CameraAttributes::getAutoExposureEnabled, &CameraAttributes::setAutoExposureEnabled),
        "autoExposureScale", sol::property(&CameraAttributes::getAutoExposureScale, &CameraAttributes::setAutoExposureScale),
        "autoExposureSpeed", sol::property(&CameraAttributes::getAutoExposureSpeed, &CameraAttributes::setAutoExposureSpeed),
        "exposureMultiplier", sol::property(&CameraAttributes::getExposureMultiplier, &CameraAttributes::setExposureMultiplier),
        "exposureSensitivity", sol::property(&CameraAttributes::getExposureSensitivity, &CameraAttributes::setExposureSensitivity),
        "cast", [](bxtk::core::Resource* res) {
            return new CameraAttributes(Object::cast_to<GodotCameraAttributes>(res->getResource()));
        }
    );
}