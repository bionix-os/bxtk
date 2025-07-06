#include "array_occluder3d.h"

void bxtk::spatial::bindArrayOccluder3D(sol::state_view& lua) {
    lua.new_usertype<bxtk::spatial::ArrayOccluder>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new bxtk::spatial::ArrayOccluder(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, Occluder3D>(),
        "indicies", sol::property(&ArrayOccluder::getIndices, &ArrayOccluder::setIndices),
        "vertices", sol::property(&ArrayOccluder::getVertices, &ArrayOccluder::setVertices),
        "setArrays", &ArrayOccluder::setArrays,
        "cast", [](bxtk::core::Resource* instance) {
            return new ArrayOccluder(godot::Object::cast_to<GodotArrayOccluder3D>(instance->getResource()));
        }
    );
}