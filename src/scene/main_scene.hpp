#pragma once
#include <core/window.hpp>
#include <ui/triangle.hpp>

class MainScene : public core::Window
{
public:
    void run(std::shared_ptr<core::Canvas> renderer) override;

private:
    ui::Triangle triangle;
};