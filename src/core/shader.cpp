#include "shader.hpp"

core::Shader::Shader(const char *vertex_path, const char *fragment_path)
{
    compile(get_shader(ShaderType::Vertex, vertex_path), get_shader(ShaderType::Fragment, fragment_path));
}

unsigned int core::Shader::get_program_id()
{
    if (mProgram_id == 0)
    {
        throw std::runtime_error("ERROR::SHADER::PROGRAM::ID_NOT_ASSIGNED\n please call compile function first");
    }
    return mProgram_id;
}

int core::Shader::get_shader(ShaderType type, const char *path)
{

    std::string source = load_file(path);

    const char *source_c = source.c_str();
    unsigned int shader_id;
    shader_id = glCreateShader((type == core::ShaderType::Vertex) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    glShaderSource(shader_id, 1, &source_c, nullptr);
    glCompileShader(shader_id);
    int success;
    char info_log[512];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader_id, 512, nullptr, info_log);
        std::string aType = (type == core::ShaderType::Vertex) ? "vertex" : "fragment";
        throw std::runtime_error("ERROR::SHADER::COMPILATION_FAILED " + aType + std::string(info_log));
    }
    return shader_id;
}

void core::Shader::compile(unsigned int vertex_shader, unsigned int fragment_shader)
{
    mProgram_id = glCreateProgram();
    glAttachShader(mProgram_id, vertex_shader);
    glAttachShader(mProgram_id, fragment_shader);
    glLinkProgram(mProgram_id);
    int success;
    char info_log[512];
    glGetProgramiv(mProgram_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(mProgram_id, 512, nullptr, info_log);
        throw std::runtime_error("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + std::string(info_log));
    }
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

std::string core::Shader::load_file(const char *path)
{
    std::string shader;
    std::ifstream shader_file;
    shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        shader_file.open(path);

        if (!shader_file.is_open())
        {
            throw std::runtime_error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_OPENED");
        }

        std::stringstream shader_buffer;
        shader_buffer << shader_file.rdbuf();
        shader = shader_buffer.str();

        shader_file.close();
    }
    catch (const std::ifstream::failure &e)
    {
        throw std::runtime_error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " + std::string(e.what()));
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("ERROR::SHADER::UNEXPECTED_ERROR: " + std::string(e.what()));
    }
    return shader;
}
