#ifndef BIND_IO_CLASSES_H
#define BIND_IO_CLASSES_H

#include <sol/sol.hpp>

namespace bxtk::core::io {
    void bindIoClasses(sol::state& lua);
}

#endif //BIND_IO_CLASSES_H