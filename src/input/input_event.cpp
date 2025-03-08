#include "input_event.h"

void sunaba::input::bindInputEvent(sol::state_view& lua) {
    lua.new_usertype<InputEvent>("InputEvent",
        sol::constructors<InputEvent(), InputEvent(GodotInputEvent*)>(),
        sol::base_classes, sol::bases<sunaba::core::Resource>(),
        "device", sol::property(&InputEvent::getDevice, &InputEvent::setDevice),
        "accumulate", &InputEvent::accumulate,
        "asText", &InputEvent::asText,
        "getActionStrength", &InputEvent::getActionStrength,
        "isAction", &InputEvent::isAction,
        "isActionPressed", &InputEvent::isActionPressed,
        "isActionReleased", &InputEvent::isActionReleased,
        "isActionType", &InputEvent::isActionType,
        "isCanceled", &InputEvent::isCanceled,
        "isEcho", &InputEvent::isEcho,
        "isMatch", &InputEvent::isMatch,
        "isPressed", &InputEvent::isPressed,
        "isReleased", &InputEvent::isReleased,
        "xformedBy", &InputEvent::xformedBy,
        "cast", [](sunaba::core::Resource* instance) {
            return new InputEvent(godot::Object::cast_to<GodotInputEvent>(instance->getResource()));
        }
    );
}