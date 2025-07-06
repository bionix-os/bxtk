#include "input_event_mouse.h"

void bxtk::input::bindInputEventMouse(sol::state_view& lua) {
    lua.new_usertype<InputEventMouse>("InputEventMouse",
        "new", sol::factories(
            []() { return new InputEventMouse(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::input::InputEvent>(),
        "buttonMask", sol::property(&InputEventMouse::getButtonMask, &InputEventMouse::setButtonMask),
        "globalPosition", sol::property(&InputEventMouse::getGlobalPosition, &InputEventMouse::setGlobalPosition),
        "position", sol::property(&InputEventMouse::getPosition, &InputEventMouse::setPosition),
        "cast", [](bxtk::core::Resource* instance) {
            return new InputEventMouse(godot::Object::cast_to<GodotInputEventMouse>(instance->getResource()));
        }
    );
}