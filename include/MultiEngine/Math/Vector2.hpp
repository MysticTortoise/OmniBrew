#pragma once

#include "MultiEngine/Math/MathMacros.hpp"

namespace MultiEngine::Math{
    class Vector2{
        public:
        float x = 0;
        float y = 0;
        Vector2(float x = 0, float y = 0);

        HEADER_MATH_MACRO(Vector2,Vector2)
        HEADER_MATH_MACRO(Vector2,float)

    };
}