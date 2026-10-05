#pragma once

#include "Shape.h"

struct Square : public Shape {
    Square();
private:
    static constexpr float verticals[18] = {
      -0.1f, 0.1f, 0.0f,  // Top-left
      0.1f, 0.1f, 0.0f,  // Top-right
      -0.1f, -0.1f, 0.0f,   // Bottom-left

     -0.1f, -0.1f, 0.0f,  // Bottom-left
      0.1f, 0.1f, 0.0f,  // Top-right
      0.1f, -0.1f, 0.0f  // Bottom-right
    };
};