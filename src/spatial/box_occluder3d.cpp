#include "box_occluder3d.h"

void bxtk::spatial::bindBoxOccluder3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::BoxOccluder>("BoxOccluder3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::BoxOccluder(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, Occluder3D>(),
        "size", sol::property(&BoxOccluder::getSize, &BoxOccluder::setSize),
        "cast", [](bxtk::core::Resource* instance) {
            return new BoxOccluder(godot::Object::cast_to<GodotBoxOccluder3D>(instance->getResource()));
        }
    );
}