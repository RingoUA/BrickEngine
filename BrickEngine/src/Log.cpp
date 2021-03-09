#include "Log.hpp"

namespace Brick {

void Log::init() {
    spdlog::set_pattern("[%H:%M:%S][%^%l%$] [thread %t] %v");
}

void Log::SetLevel(Level lvl) {
    spdlog::set_level(static_cast<spdlog::level::level_enum>(lvl));
}

} // Brick