#pragma once

#include "Shape.h"

struct Triangle : public Shape {
    using Shape::Shape;
    float verticals[9] = {
      0.1f,  0.0f, 0.0f,  // Top-left
     -0.1f,  -0.1f, 0.0f,  // Top-right
     -0.1f, 0.1f, 0.0f   // Bottom-right
    };
};