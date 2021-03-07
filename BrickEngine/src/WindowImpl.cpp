#include "WindowImpl.hpp"

// TODO: replase this func to some helper file
constexpr float normalize(const float& n) {
    return n/255.f;
}

namespace Brick {

WindowImpl::WindowImpl()
{
    glfwSetErrorCallback([](int error_code, const char* description) {

    });
    if (glfwInit()) {
        window = glfwCreateWindow(640, 480, "window", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, this);
        initCallback();
    } else {
        glfwTerminate();
    }
}

WindowImpl::~WindowImpl() {
    glfwTerminate();
}

int32_t WindowImpl::getWidth() const {
    return width;
}

int32_t WindowImpl::getHeight() const {
    return height;
}

int32_t WindowImpl::getXPosition() const {
    return x_pos;
}

int32_t WindowImpl::getYPosition() const {
    return y_pos;
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

void WindowImpl::initCallback() {
    // window callcack
    glfwSetWindowPosCallback(window, [](GLFWwindow* window, int xpos, int ypos) {
        WindowImpl& _window = *reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
        _window.x_pos = xpos;
        _window.y_pos = ypos;
    });
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        WindowImpl& _window = *reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
        _window.width = width;
        _window.height = height;
    });
    glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
    });
    glfwSetWindowRefreshCallback(window, [](GLFWwindow* window) {
    });
    glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) {
    });
    glfwSetWindowIconifyCallback(window, [](GLFWwindow* window, int iconified) {
    });
    glfwSetWindowMaximizeCallback(window, [](GLFWwindow* window, int maximized) {
    });
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
    });
    glfwSetWindowContentScaleCallback(window, [](GLFWwindow* window, float xscale, float yscale) {
    });
    // input callback
    glfwSetKeyCallback (window, [] (GLFWwindow* window, int key, int scancode, int action, int mods) {
    });
 	glfwSetCharCallback (window, [] (GLFWwindow* window, unsigned int codepoint) {
    });
 	glfwSetCharModsCallback (window, [] (GLFWwindow* window, unsigned int codepoint, int mods) {
    });
 	glfwSetMouseButtonCallback (window, [] (GLFWwindow* window, int button, int action, int mods) {
    });
 	glfwSetCursorPosCallback (window, [] (GLFWwindow* window, double xpos, double ypos) {
    });
 	glfwSetCursorEnterCallback (window, [] (GLFWwindow* window, int entered) {
    });
 	glfwSetScrollCallback (window, [] (GLFWwindow* window, double xoffset, double yoffset) {
    });
 	glfwSetDropCallback (window, [] (GLFWwindow* window, int path_count, const char* paths[]) {
    });
}

}