#include "triangle.hpp"
#include <iostream>
#include <filesystem>

ui::Triangle::Triangle()
{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path vertexPath = cwd / "src" / "ui" / "shaders" / "triangle.vs";
    std::filesystem::path fragmentPath = cwd / "src" / "ui" / "shaders" / "triangle.fs";

    shader = core::Shader(vertexPath.c_str(), fragmentPath.c_str());

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};

    glGenVertexArrays(1, &vba);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vba);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

ui::Triangle::~Triangle()
{
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vba);
    glDeleteProgram(shader.get_program_id());
}

void ui::Triangle::draw()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader.get_program_id());
    glBindVertexArray(vba);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
