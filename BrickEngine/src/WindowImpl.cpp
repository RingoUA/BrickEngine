#include "WindowImpl.hpp"

// TODO: replase this func to some helper file
constexpr float normalize(const float& n) {
    return n/255.f;
}

namespace Brick {

WindowImpl::WindowImpl() : data{}
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

WindowImpl::~WindowImpl() {
    glfwTerminate();
}

int32_t WindowImpl::getWidth() const {
    // TODO: replace get data to event system
    glfwGetWindowSize(window, &data.width, &data.height);
    return data.width;
}

int32_t WindowImpl::getHeight() const {
    // TODO: replace get data to event system
    glfwGetWindowSize(window, &data.width, &data.height);
    return data.height;
}

int32_t WindowImpl::getXPosition() const {
    // TODO: replace get data to event system
    glfwGetWindowPos(window, &data.x_pos, &data.y_pos);
    return data.x_pos;
}

int32_t WindowImpl::getYPosition() const {
    // TODO: replace get data to event system
    glfwGetWindowPos(window, &data.x_pos, &data.y_pos);
    return data.y_pos;
}

void WindowImpl::show() {
    glClearColor(normalize(27), normalize(38), normalize(44), normalize(255));
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

}