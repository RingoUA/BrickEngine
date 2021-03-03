#include "window.hpp"

constexpr float normalize(const float& n) {
    return n/255.f;
}

namespace Brick {

Window::Window()
{
    if (glfwInit()) {
        window = glfwCreateWindow(640, 480, "window", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
    } else {
        glfwTerminate();
    }
}

Window::~Window()
{
    glfwTerminate();
}

void Window::show()
{
    glClearColor(normalize(27), normalize(38), normalize(44), normalize(255));
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

} // Brick