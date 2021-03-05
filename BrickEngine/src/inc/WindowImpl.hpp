#ifndef WINDOW_IMPL_HPP
#define WINDOW_IMPL_HPP

#include <GLFW/glfw3.h>

namespace Brick {

class WindowImpl {
public:
    WindowImpl();
    ~WindowImpl();
    WindowImpl(const WindowImpl&) = delete;
    WindowImpl& operator=(WindowImpl&) = delete;
    WindowImpl(WindowImpl&&) = default;
    WindowImpl& operator=(WindowImpl&&) = default;

    void show();
private:
    GLFWwindow* window;
};

}

#endif // WINDOW_IMPL_HPP