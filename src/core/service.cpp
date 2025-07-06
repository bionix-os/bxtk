#include "service.h"

namespace bxtk::core {
    void bindService(sol::state& lua) {
        lua.new_usertype<Service>("Service", sol::no_constructor);
    }
}