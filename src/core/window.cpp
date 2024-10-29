#include "window.hpp"
#include <stdexcept>

namespace core
{

    Window::Window()
    {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!setup_window())
        {
            throw std::runtime_error("Failed to create GLFW window");
        }

        if (!setup_glad())
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        // set glViewport
        glViewport(0, 0, 800, 600);
    }

    Window::~Window()
    {

        glfwTerminate();
    }

    void Window::run(std::shared_ptr<Canvas> renderer)
    {
        glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);
    }
    void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
    bool Window::setup_window()
    {
        mWindow = glfwCreateWindow(800, 600, "Test", nullptr, nullptr);
        if (!mWindow)
        {
            return false;
        }

        glfwMakeContextCurrent(mWindow);
        return true;
    }
    bool Window::setup_glad()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            return false;
        }
        return true;
    }
}
