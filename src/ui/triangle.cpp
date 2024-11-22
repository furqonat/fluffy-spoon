#include "triangle.hpp"
#include <iostream>
#include <filesystem>
#include <cmath>

ui::Triangle::Triangle() : mVertices({-5.0f, 0.0f, 0.0f,
                                      -1.0f, -1.0f, 0.0f,
                                      -0.0f, -1.0f, 0.0f})
{

    init();
}

ui::Triangle::Triangle(float vertices[9]) : mVertices{
                                                vertices[0], vertices[1], vertices[2],
                                                vertices[3], vertices[4], vertices[5],
                                                vertices[6], vertices[7], vertices[8]}
{
    init();
}

ui::Triangle::~Triangle()
{
    glDeleteBuffers(1, &mVbo);
    glDeleteVertexArrays(1, &mVba);
    glDeleteProgram(mShader.get_program_id());
}

void ui::Triangle::draw()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(mShader.get_program_id());
    float time = glfwGetTime();
    float greenValue = sin(time) / 2.0f + 0.5f;
    int vertexColorLocation = glGetUniformLocation(mShader.get_program_id(), "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
    glBindVertexArray(mVba);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void ui::Triangle::init()
{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path vertexPath = cwd / "src" / "ui" / "shaders" / "triangle.vs";
    std::filesystem::path fragmentPath = cwd / "src" / "ui" / "shaders" / "triangle.fs";

    mShader = core::Shader(vertexPath.c_str(), fragmentPath.c_str());

    glGenVertexArrays(1, &mVba);
    glGenBuffers(1, &mVbo);

    glBindVertexArray(mVba);

    glBindBuffer(GL_ARRAY_BUFFER, mVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}
