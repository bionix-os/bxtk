#include "event.h"

using namespace godot;

void bxtk::core::bindEvent(sol::state &lua) {
    lua.new_usertype<bxtk::core::Event>("Event",
        "new", sol::factories(
            []() { return new bxtk::core::Event(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject>(),
        "connect", &bxtk::core::Event::connectLua,
        "disconnect", &bxtk::core::Event::disconnectLua,
        "emit", &bxtk::core::Event::emitLua,
        "clear", &bxtk::core::Event::clear
    );
}