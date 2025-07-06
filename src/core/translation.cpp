#include "translation.h"

void bxtk::core::bindTranslation(sol::state &lua) {
    lua.new_usertype<bxtk::core::Translation>("Translation",
        "new", sol::factories(
            []() { return new bxtk::core::Translation(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::Resource>(),
        "locale", sol::property(
            &bxtk::core::Translation::getLocale,
            &bxtk::core::Translation::setLocale
        ),
        "addMessage", &bxtk::core::Translation::addMessage,
        "addPluralMessage", &bxtk::core::Translation::addPluralMessage,
        "eraseMessage", &bxtk::core::Translation::eraseMessage,
        "getMessage", &bxtk::core::Translation::getMessage,
        "getMessageCount", &bxtk::core::Translation::getMessageCount,
        "getMessageList", &bxtk::core::Translation::getMessageList,
        "getPluralMessage", &bxtk::core::Translation::getPluralMessage,
        "getTranslatedMessageList", &bxtk::core::Translation::getTranslatedMessageList,
        "cast", [](Resource* instance) {
            return new Translation(godot::Object::cast_to<GodotTranslation>(instance->getResource()));
        }
    );
}