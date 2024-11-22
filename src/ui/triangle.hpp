#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/canvas.hpp>
#include <core/shader.hpp>
#include <array>

namespace ui
{
    class Triangle : public core::Canvas
    {
    public:
        Triangle();
        Triangle(float vertices[9]);
        ~Triangle();

        void draw() override;

    private:
        void init();

    private:
        core::Shader mShader;
        std::array<float, 9> mVertices;
        unsigned int mVbo;
        unsigned int mVba;
    };
}