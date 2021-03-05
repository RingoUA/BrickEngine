#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>

namespace Brick {

class WindowImpl;
class Window {
public:
    Window();
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(Window&) = delete;
    Window(Window&&);
    Window& operator=(Window&&);

    void show();
private:
    std::unique_ptr<WindowImpl> pImpl;
};

} // Brick

#endif // WINDOW_HPP