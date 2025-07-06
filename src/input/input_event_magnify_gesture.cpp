#include "input_event_magnify_gesture.h"

void bxtk::input::bindInputEventMagnifyGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventMagnifyGesture>("InputEventMagnifyGesture",
        "new", sol::factories(
            []() { return new InputEventMagnifyGesture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::input::InputEvent, bxtk::input::InputEventGesture>(),
        "factor", sol::property(&InputEventMagnifyGesture::getFactor, &InputEventMagnifyGesture::setFactor),
        "cast", [](bxtk::core::Resource* instance) {
            return new InputEventMagnifyGesture(godot::Object::cast_to<GodotInputEventMagnifyGesture>(instance->getResource()));
        }
    );
}