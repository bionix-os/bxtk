#include "io_index.h"

namespace bxtk::core::io {
    std::map<sol::state_view, IoManager*> IoIndex::ioManagers;
}