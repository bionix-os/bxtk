#include "shader.h"

void bxtk::core::bindShader(sol::state& lua) {
    lua.new_usertype<bxtk::core::Shader>("Shader",
        "new", sol::factories(
            []() { return new bxtk::core::Shader(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "code", sol::property(
            &bxtk::core::Shader::getCode,
            &bxtk::core::Shader::setCode
        ),
        "defaultTextureParameter", &bxtk::core::Shader::getDefaultTextureParameter,
        "getMode", &bxtk::core::Shader::getMode,
        "getShaderUniformList", &bxtk::core::Shader::getShaderUniformList,
        "cast", [](Resource* instance) {
            return new Shader(godot::Object::cast_to<GodotShader>(instance->getResource()));
        }
    );
}