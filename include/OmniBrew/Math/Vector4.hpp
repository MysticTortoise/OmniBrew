#pragma once

#include "OmniBrew/Math/MathMacros.hpp"
#include "OmniBrew/Math/Vector2.hpp"
#include "OmniBrew/Math/Vector3.hpp"

namespace OmniBrew::Math {
    class Vector4 {
    public:
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;
        Vector4(float x = 0, float y = 0, float z = 0, float w = 0);

        HEADER_MATH_MACRO(Vector4, float)
        HEADER_MATH_MACRO(Vector4, Vector2)
        HEADER_MATH_MACRO(Vector4, Vector3)
        HEADER_MATH_MACRO(Vector4, Vector4)

    };
}