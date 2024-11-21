#pragma once

#include "OmniBrew/Math/MathMacros.hpp"
#include "OmniBrew/Math/Vector2.hpp"

namespace OmniBrew::Math{
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