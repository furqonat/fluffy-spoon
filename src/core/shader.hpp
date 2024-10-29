#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>

#include <iostream>

namespace core
{
    enum ShaderType
    {
        Vertex,
        Fragment
    };

    class Shader
    {
    public:
        Shader() = default;
        Shader(const char *vertex_path, const char *fragment_path);
        unsigned int get_program_id();

        ~Shader() = default;

    private:
        void compile(unsigned int vertex_shader, unsigned int fragment_shader);
        int get_shader(ShaderType type, const char *path);
        std::string load_file(const char *path);

    private:
        ShaderType mType;
        unsigned int mProgram_id;
    };
}