#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/canvas.hpp>
#include <core/shader.hpp>

namespace ui
{
    class Triangle : public core::Canvas
    {
    public:
        Triangle();
        ~Triangle();

        void draw() override;

    private:
        core::Shader shader;
        unsigned int vbo;
        unsigned int vba;
    };
}