#include "resource.h"

void bxtk::core::bindResource(sol::state &lua) {
    lua.new_usertype<bxtk::core::Resource>("Resource",
        "new", sol::factories(
            []() { return new bxtk::core::Resource(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject>(),
        "duplicate", &bxtk::core::Resource::duplicate,
        "emitChanged", &bxtk::core::Resource::emitChanged,
        "isNull", &bxtk::core::Resource::isNull,
        "cast", [](Resource* instance) {
            return new Resource(godot::Object::cast_to<GodotResource>(instance->getResource()));
        }
    );
}