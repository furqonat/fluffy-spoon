#include "main_scene.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void MainScene::run(std::shared_ptr<core::Canvas> renderer)
{
    while (!glfwWindowShouldClose(mWindow))
    {
        if (renderer != nullptr)
        {
            renderer->on_input(mWindow);
            renderer->draw();
        }
        triangle.draw();
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
}
