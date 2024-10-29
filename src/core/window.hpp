#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "canvas.hpp"

namespace core
{

    class Window
    {
    public:
        Window();
        ~Window();

        virtual void run(std::shared_ptr<Canvas> renderer);

    protected:
        GLFWwindow *mWindow;

    private:
        bool setup_window();
        bool setup_glad();
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    };
}