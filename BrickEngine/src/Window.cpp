#include "Window.hpp"

#include "WindowImpl.hpp"

namespace Brick {

Window::Window() : pImpl{std::make_unique<WindowImpl>()}
{
}

Window::~Window() = default;
Window::Window(Window&&) = default;
Window& Window::operator=(Window&&) = default;

int32_t Window::getWidth() const {
    return pImpl->getWidth();
}

int32_t Window::getHeight() const {
    return pImpl->getHeight();
}

int32_t Window::getXPosition() const {
    return pImpl->getXPosition();
}

int32_t Window::getYPosition() const {
    return pImpl->getYPosition();
}

void Window::show()
{
    pImpl->show();
}

} // Brick