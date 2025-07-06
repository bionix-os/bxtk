#include "shader_include.h"

void bxtk::core::bindShaderInclude(sol::state &lua) {
    lua.new_usertype<bxtk::core::ShaderInclude>("ShaderInclude",
        "new", sol::factories(
            []() { return new bxtk::core::ShaderInclude(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "code", sol::property(
            &bxtk::core::ShaderInclude::getCode, 
            &bxtk::core::ShaderInclude::setCode
        ),
        "cast", [](Resource* instance) {
            return new ShaderInclude(godot::Object::cast_to<GodotShaderInclude>(instance->getResource()));
        }
    );
}