#ifndef WINDOW_IMPL_HPP
#define WINDOW_IMPL_HPP

#include <GLFW/glfw3.h>

namespace Brick {

struct WindowData{
    int32_t width;
    int32_t height;
    int32_t x_pos;
    int32_t y_pos;
};

class WindowImpl {
public:
    WindowImpl();
    ~WindowImpl();
    WindowImpl(const WindowImpl&) = delete;
    WindowImpl& operator=(WindowImpl&) = delete;
    WindowImpl(WindowImpl&&) = default;
    WindowImpl& operator=(WindowImpl&&) = default;

    int32_t getWidth() const;
    int32_t getHeight() const;
    int32_t getXPosition() const;
    int32_t getYPosition() const;

    void show();
private:
    GLFWwindow* window;
    // TODO: replace set data to this struct with event system
    mutable WindowData data;
};

}

#endif // WINDOW_IMPL_HPP