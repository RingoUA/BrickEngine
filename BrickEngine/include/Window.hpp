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

    int32_t getWidth() const;
    int32_t getHeight() const;
    int32_t getXPosition() const;
    int32_t getYPosition() const;

    void show();
private:
    std::unique_ptr<WindowImpl> pImpl;
};

} // Brick

#endif // WINDOW_HPP