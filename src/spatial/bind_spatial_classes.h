#ifndef BIND_SPATIAL_H
#define BIND_SPATIAL_H

#include <sol/sol.hpp>

namespace bxtk::spatial
{
    void bindSpatialClasses(sol::state& lua);
}

#endif