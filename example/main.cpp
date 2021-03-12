#include "Window.hpp"
#include "Log.hpp"
#include <thread>

int main(void)
{
    Brick::Log::init();
    Brick::Log::Info("main function");
    Brick::Log::SetLevel(Brick::Log::Level::trace);

    auto w = Brick::Window::Create("Test Window", 400, 800);

    int i = 0;
    w->setTickFunc([&i]() {
        Brick::Log::Info("tick: {0}", i++);
    });

    w->show();

    return 0;
}