#include "style_box_empty.h"

void bxtk::ui::bindStyleBoxEmpty(sol::state &lua) {
    using namespace sol;
    using namespace bxtk::ui;

    lua.new_usertype<StyleBoxEmpty>("StyleBoxEmpty",
        "new", sol::factories(
            []() { return new StyleBoxEmpty(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::ui::StyleBox>(),
        "cast", [](bxtk::core::Resource* p_resource) {
            return new StyleBoxEmpty(godot::Object::cast_to<GodotStyleBoxEmpty>(p_resource->getResource()));
        }
    );
}