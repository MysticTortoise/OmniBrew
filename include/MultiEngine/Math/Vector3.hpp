#pragma once

#include "MultiEngine/Math/MathMacros.hpp"
#include "MultiEngine/Math/Vector2.hpp"

namespace MultiEngine::Math{
    class Vector3{
        public:
        float x = 0;
        float y = 0;
        float z = 0;
        Vector3(float x = 0, float y = 0, float z = 0);

        HEADER_MATH_MACRO(Vector3,Vector3)
        HEADER_MATH_MACRO(Vector3,Vector2)
        HEADER_MATH_MACRO(Vector3,float)

    };
}