#include "Window.hpp"
#include "Log.hpp"
#include <thread>

int main(void)
{
    Brick::Log::init();

    Brick::Log::Info("main function");

    Brick::Log::SetLevel(Brick::Log::Level::trace);

    auto w = Brick::Window::Create("Test Window", 400, 800);

    w->show();

    return 0;
}