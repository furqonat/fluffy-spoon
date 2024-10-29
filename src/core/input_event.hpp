#pragma once
#include <GLFW/glfw3.h>
namespace core
{
    typedef GLFWwindow Event;
    class InputEvent
    {
    public:
        virtual void on_input(Event *event);
        virtual ~InputEvent() = default;
    };
}