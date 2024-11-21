#include "MultiEngine/Math/Vector2.hpp"
#include "MultiEngine/Math/MathMacros.hpp"

using namespace MultiEngine::Math;


Vector2::Vector2(float x, float y): x(x), y(y) {}

#define VECTOR2_OPERATOR_MACRO(OP) {\
    x OP##= other.x; \
    y OP##= other.y; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR2_OPERATOR_MACRO,Vector2,Vector2)

#define VECTOR2_FLOAT_OPERATOR_MACRO(OP) {\
    x OP##= other; \
    y OP##= other; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR2_FLOAT_OPERATOR_MACRO,Vector2,float)