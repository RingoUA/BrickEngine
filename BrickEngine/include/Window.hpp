#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <string>
#include <functional>

namespace Brick {

class Window {
    Window(const Window&) = delete;
    Window& operator=(Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;
public:
    virtual ~Window() = default;

    virtual int32_t getWidth() const noexcept = 0;
    virtual int32_t getHeight() const noexcept = 0;
    virtual int32_t getXPosition() const noexcept = 0;
    virtual int32_t getYPosition() const noexcept = 0;

    virtual void show() = 0;

    static std::unique_ptr<Window> Create(std::string title = "Brick", int32_t width = 1024, int32_t height = 768);
protected:
    Window() = default;
};

} // Brick

#endif // WINDOW_HPP