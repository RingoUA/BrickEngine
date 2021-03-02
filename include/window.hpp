#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>

namespace Brick {

class Window {
public:
    Window();
    ~Window();

    void show();
private:
    GLFWwindow* window;
};

} // Brick

#endif // WINDOW_HPP