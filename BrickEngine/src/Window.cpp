#include "Window.hpp"

#include "WindowImpl.hpp"

namespace Brick {

Window::Window() : pImpl{std::make_unique<WindowImpl>()}
{
}

Window::~Window() = default;
Window::Window(Window&&) = default;
Window& Window::operator=(Window&&) = default;

void Window::show()
{
    pImpl->show();
}

} // Brick