#include "input_event_gesture.h"

void bxtk::input::bindInputEventGesture(sol::state_view& lua) {
    lua.new_usertype<InputEventGesture>("InputEventGesture",
        "new", sol::factories(
            []() { return new InputEventGesture(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::input::InputEvent>(),
        "position", sol::property(&InputEventGesture::getPosition, &InputEventGesture::setPosition),
        "cast", [](bxtk::core::Resource* instance) {
            return new InputEventGesture(godot::Object::cast_to<GodotInputEventGesture>(instance->getResource()));
        }
    );
}