#include "WindowImpl.hpp"

#include "Log.hpp"

// TODO: replase this func to some helper file
constexpr float normalize(const float& n) {
    return n/255.f;
}

namespace Brick {

int32_t WindowImpl::window_counter = 0;

WindowImpl::WindowImpl()
{
    glfwSetErrorCallback([](int error_code, const char* description) {
        Log::Error("error_code = {0}, description: {1}", error_code, description);
    });
    static bool success = false;
    if (!window_counter) {
        success = glfwInit();
    }
    if (success) {
        window = glfwCreateWindow(640, 480, "window", NULL, NULL);
        if (!window) {
            glfwTerminate();
        } else {
            ++window_counter;
        }
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, this);
        initCallback();
    } else {
        glfwTerminate();
    }
}

WindowImpl::~WindowImpl() {
    --window_counter;
    if (window_counter) {
        glfwDestroyWindow(window);
    } else {
        glfwTerminate();
    }
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

        Log::Trace("WindowPos: x = {0}, y = {1}", xpos, ypos);
    });
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        WindowImpl& _window = *reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
        _window.width = width;
        _window.height = height;

        Log::Trace("WindowSize: width = {0}, height = {1}", width, height);
    });
    glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
        Log::Trace("WindowClose");
    });
    glfwSetWindowRefreshCallback(window, [](GLFWwindow* window) {
        Log::Trace("WindowRefresh");
    });
    glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) {
        Log::Trace("WindowFocus: focused = {0}", static_cast<bool>(focused));
    });
    glfwSetWindowIconifyCallback(window, [](GLFWwindow* window, int iconified) {
        Log::Trace("WindowIconify: iconified = {0}", iconified);
    });
    glfwSetWindowMaximizeCallback(window, [](GLFWwindow* window, int maximized) {
        Log::Trace("WindowMaximize: maximized = {0}", maximized);
    });
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        Log::Trace("FramebufferSize: width = {0}, height = {1}", width, height);
    });
    glfwSetWindowContentScaleCallback(window, [](GLFWwindow* window, float xscale, float yscale) {
        Log::Trace("WindowContentScale: xscale = {0}, yscale = {1}", xscale, yscale);
    });
    // input callback
    glfwSetKeyCallback (window, [] (GLFWwindow* window, int key, int scancode, int action, int mods) {
        Log::Trace("Key: key = {0}, scancode = {1}, action = {2}, mods = {3}", key, scancode, action, mods);
    });
 	glfwSetCharCallback (window, [] (GLFWwindow* window, unsigned int codepoint) {
        Log::Trace("Char: codepoint = {0}", codepoint);
    });
 	glfwSetCharModsCallback (window, [] (GLFWwindow* window, unsigned int codepoint, int mods) {
        Log::Trace("CharMods: codepoint = {0}, mods = {1}", codepoint, mods);
    });
 	glfwSetMouseButtonCallback (window, [] (GLFWwindow* window, int button, int action, int mods) {
        Log::Trace("MouseButton: button = {0}, action = {1}, mods = {2}", button, action, mods);
    });
 	glfwSetCursorPosCallback (window, [] (GLFWwindow* window, double xpos, double ypos) {
        Log::Trace("CursorPos: x = {0}, y = {1}", xpos, ypos);
    });
 	glfwSetCursorEnterCallback (window, [] (GLFWwindow* window, int entered) {
        Log::Trace("CursorEnter: entered = {0}", entered);
    });
 	glfwSetScrollCallback (window, [] (GLFWwindow* window, double xoffset, double yoffset) {
        Log::Trace("Scroll: xoffset = {0}, yoffset = {1}", xoffset, yoffset);
    });
 	glfwSetDropCallback (window, [] (GLFWwindow* window, int path_count, const char* paths[]) {
        Log::Trace("Drop: path_count = {0}", path_count);
    });
    glfwSetJoystickCallback([](int jid, int event) {
        Log::Trace("Joystick: jid = {0}, event = {1}", jid, event);
    });
}

}