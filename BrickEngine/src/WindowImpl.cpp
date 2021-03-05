#include "WindowImpl.hpp"

// TODO: replase this func to some helper file
constexpr float normalize(const float& n) {
    return n/255.f;
}

namespace Brick {

WindowImpl::WindowImpl() {
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

WindowImpl::~WindowImpl() {
    glfwTerminate();
}

void WindowImpl::show(){
    glClearColor(normalize(27), normalize(38), normalize(44), normalize(255));
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

}