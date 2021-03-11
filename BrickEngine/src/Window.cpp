#include "Window.hpp"
#include "WindowOpenGL.hpp"
#include "Log.hpp"

namespace Brick {

std::unique_ptr<Window> Window::Create(std::string title, int32_t width, int32_t height) {
    Log::Info("Create Window");
    return std::make_unique<WindowOpenGL>(title, width, height);
}

} // Brick