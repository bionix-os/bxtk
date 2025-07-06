#include "platform_service.h"

namespace bxtk::core {
    std::string PlatformService::platformName = "BXTK";
    godot::OS* PlatformService::osSingleton = nullptr;

    void bindPlatformService(sol::state& lua) {
        auto ut = lua.new_usertype<PlatformService>("PlatformService",
            sol::no_constructor,
            sol::base_classes, sol::bases<Service>(),
            "name", sol::readonly_property(
                &PlatformService::getPlatformName
            ),
            "deviceType", sol::readonly_property(
                &PlatformService::getDeviceType
            ),
            "osName", sol::readonly_property(
                &PlatformService::getOSName
            )
        );
        lua["PlatformService"] = ut;
    }
}