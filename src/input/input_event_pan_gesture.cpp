#include "input_event_pan_gesture.h"

void bxtk::input::bindInputEventPanGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventPanGesture>("InputEventPanGesture",
        "new", sol::factories(
            []() { return new InputEventPanGesture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::input::InputEvent, bxtk::input::InputEventGesture>(),
        "delta", sol::property(&InputEventPanGesture::getDelta, &InputEventPanGesture::setDelta),
        "cast", [](bxtk::core::Resource* instance) {
            return new InputEventPanGesture(godot::Object::cast_to<GodotInputEventPanGesture>(instance->getResource()));
        }
    );
}