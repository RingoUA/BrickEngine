#include "Window.hpp"
#include "Log.hpp"

int main(void)
{
    Brick::Log::init();


    Brick::Log::Info("Default log level --------------------------------------------------");
    Brick::Log::Trace("Trace log!!!");
    Brick::Log::Debug("Debug log!!!");
    Brick::Log::Info("Info log!!!");
    Brick::Log::Warn("Warn log!!!");
    Brick::Log::Error("Error log!!!");
    Brick::Log::Critical("Critical log!!!");
    Brick::Log::Info("Set log level to debug --------------------------------------------------");
    Brick::Log::SetLevel(Brick::Log::Level::debug);
    Brick::Log::Trace("Trace log!!!");
    Brick::Log::Debug("Debug log!!!");
    Brick::Log::Info("Info log!!!");
    Brick::Log::Warn("Warn log!!!");
    Brick::Log::Error("Error log!!!");
    Brick::Log::Critical("Critical log!!!");
    Brick::Log::Info("Set log level to trace --------------------------------------------------");
    Brick::Log::SetLevel(Brick::Log::Level::trace);
    Brick::Log::Trace("Trace log!!!");
    Brick::Log::Debug("Debug log!!!");
    Brick::Log::Info("Info log!!!");
    Brick::Log::Warn("Warn log!!!");
    Brick::Log::Error("Error log!!!");
    Brick::Log::Critical("Critical log!!!");
    Brick::Log::Info("Set log level to warn --------------------------------------------------");
    Brick::Log::SetLevel(Brick::Log::Level::warn);
    Brick::Log::Trace("Trace log!!!");
    Brick::Log::Debug("Debug log!!!");
    Brick::Log::Info("Info log!!!");
    Brick::Log::Warn("Warn log!!!");
    Brick::Log::Error("Error log!!!");
    Brick::Log::Critical("Critical log!!!");
    Brick::Log::Critical("Set log level to off --------------------------------------------------");
    Brick::Log::SetLevel(Brick::Log::Level::off);
    Brick::Log::Trace("Trace log!!!");
    Brick::Log::Debug("Debug log!!!");
    Brick::Log::Info("Info log!!!");
    Brick::Log::Warn("Warn log!!!");
    Brick::Log::Error("Error log!!!");
    Brick::Log::Critical("Critical log!!!");

    Brick::Log::SetLevel(Brick::Log::Level::info);

    Brick::Window w;
    w.show();
    return 0;
}