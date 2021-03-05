#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>

#include <memory>

namespace Brick {

class Window {
public:
    Window();
    ~Window();

    void show();
private:
    GLFWwindow* window;
    class WindowImpl;
    std::unique_ptr<WindowImpl> pImpl;
};

} // Brick

#endif // WINDOW_HPP