#pragma once
#include "input_event.hpp"
#include <memory>

namespace core
{
    class Canvas : public InputEvent
    {
    public:
        virtual void draw() = 0;

        virtual ~Canvas() = default;
    };
}
