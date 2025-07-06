#include "input_event_joypad_motion.h"

void bxtk::input::bindInputEventJoypadMotion(sol::state_view& lua) {
    lua.new_usertype<InputEventJoypadMotion>("InputEventJoypadMotion",
        "new", sol::factories(
            []() { return new InputEventJoypadMotion(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::input::InputEvent>(),
        "axis", sol::property(&InputEventJoypadMotion::getAxis, &InputEventJoypadMotion::setAxis),
        "axisValue", sol::property(&InputEventJoypadMotion::getAxisValue, &InputEventJoypadMotion::setAxisValue),
        "cast", [](bxtk::core::Resource* instance) {
            return new InputEventJoypadMotion(godot::Object::cast_to<GodotInputEventJoypadMotion>(instance->getResource()));
        }
    );
}