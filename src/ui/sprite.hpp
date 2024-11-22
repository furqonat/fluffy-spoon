#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/canvas.hpp>
#include <core/shader.hpp>
#include <stb_image.h>

namespace ui
{
    class Sprite : public core::Canvas
    {
    public:
        Sprite();
        ~Sprite();
        void draw() override;

    private:
        core::Shader mShader;
        float mVertices[32];
        unsigned int mVbo, mVba, mEbo;
        unsigned char *mImageData;
        int mWidth, mHeight, mChannels;
        unsigned int mTexture;
    };
}