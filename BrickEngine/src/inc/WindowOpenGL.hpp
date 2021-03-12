#ifndef WINDOW_IMPL_HPP
#define WINDOW_IMPL_HPP

#include <GLFW/glfw3.h>
#include <functional>

#include "Window.hpp"

namespace Brick {

class WindowOpenGL : public Window {
public:
    WindowOpenGL() = delete;
    WindowOpenGL(std::string title, int32_t width, int32_t height);
    ~WindowOpenGL() final;
    WindowOpenGL(const WindowOpenGL&) = delete;
    WindowOpenGL& operator=(WindowOpenGL&) = delete;
    WindowOpenGL(WindowOpenGL&&) = default;
    WindowOpenGL& operator=(WindowOpenGL&&) = default;

    int32_t getWidth() const noexcept final;
    int32_t getHeight() const noexcept final;
    int32_t getXPosition() const noexcept final;
    int32_t getYPosition() const noexcept final;

    void show() final;
    void setTickFunc(Window::TickFunc tick_func) final;

private:
    void initCallback();

private:
    GLFWwindow* window;
    int32_t width;
    int32_t height;
    int32_t x_pos;
    int32_t y_pos;

    static int32_t window_counter;

    Window::TickFunc tickFunction = [](){};
};

}

#endif // WINDOW_IMPL_HPP