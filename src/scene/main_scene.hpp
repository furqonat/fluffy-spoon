#pragma once
#include <core/window.hpp>
#include <ui/triangle.hpp>

class MainScene : public core::Window
{
public:
    MainScene();
    void run(std::shared_ptr<core::Canvas> renderer) override;

private:
    float vertices[9] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
    ui::Triangle triangle, triangle2;
};