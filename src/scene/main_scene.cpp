#include "main_scene.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

MainScene::MainScene() : triangle2{vertices}
{
}

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
        triangle2.draw();
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
}
