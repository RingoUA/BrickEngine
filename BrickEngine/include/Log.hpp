#ifndef LOG_HPP
#define LOG_HPP

#include <spdlog/spdlog.h>

namespace Brick {

class Log {
public:
    enum class Level
    {
        trace = 0,
        debug = 1,
        info = 2,
        warn = 3,
        err = 4,
        critical = 5,
        off = 6
    };

    static void init();

    static void SetLevel(Level);

    template<class... T>
    static void Trace(T&&... t) {
        spdlog::trace(std::forward<T>(t)...);
    }

    template<class... T>
    static void Debug(T&&... t) {
        spdlog::debug(std::forward<T>(t)...);
    }

    template<class... T>
    static void Info(T&&... t) {
        spdlog::info(std::forward<T>(t)...);
    }

    template<class... T>
    static void Warn(T&&... t) {
        spdlog::warn(std::forward<T>(t)...);
    }

    template<class... T>
    static void Error(T&&... t) {
        spdlog::error(std::forward<T>(t)...);
    }

    template<class... T>
    static void Critical(T&&... t) {
        spdlog::critical(std::forward<T>(t)...);
    }
};

} // Brick

#endif // LOG_HPP