#include "input_event_screen_touch.h"

void bxtk::input::bindInputEventScreenTouch(sol::state_view& lua) {
    lua.new_usertype<bxtk::input::InputEventScreenTouch>("InputEventScreenTouch",
        "new", sol::factories(
            []() { return new bxtk::input::InputEventScreenTouch(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::input::InputEvent, bxtk::input::InputEventFromWindow>(),
        "canceled", sol::property(
            &InputEventScreenTouch::isCanceled,
            &InputEventScreenTouch::setCanceled
        ),
        "doubleTap", sol::property(
            &InputEventScreenTouch::isDoubleTap,
            &InputEventScreenTouch::setDoubleTap
        ),
        "index", sol::property(
            &InputEventScreenTouch::getIndex,
            &InputEventScreenTouch::setIndex
        ),
        "position", sol::property(
            &InputEventScreenTouch::getPosition,
            &InputEventScreenTouch::setPosition
        ),
        "pressed", sol::property(
            &InputEventScreenTouch::isPressed,
            &InputEventScreenTouch::setPressed
        ),
        "cast", [](bxtk::core::Resource* instance) {
            return new InputEventScreenTouch(godot::Object::cast_to<GodotInputEventScreenTouch>(instance->getResource()));
        }
    );
}