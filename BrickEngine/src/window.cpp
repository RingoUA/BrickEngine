#include "Window.hpp"

constexpr float normalize(const float& n) {
    return n/255.f;
}

namespace Brick {

class Window::WindowImpl {
public:
    WindowImpl() = default;
    ~WindowImpl() = default;
    WindowImpl(const WindowImpl&) = delete;
    WindowImpl& operator=(WindowImpl&) = delete;
    WindowImpl(WindowImpl&&) = default;
    WindowImpl& operator=(WindowImpl&&) = default;
};

Window::Window() : pImpl{std::make_unique<WindowImpl>()}
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