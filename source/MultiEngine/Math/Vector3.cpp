#include "MultiEngine/Math/Vector3.hpp"
#include "MultiEngine/Math/MathMacros.hpp"

using namespace MultiEngine::Math;


Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}

// Yes, this is stupid. Still better than writing the same fucking operator overload 50 billion times!!
#define VECTOR3_VECTOR3_OPERATOR_MACRO(OP) {\
    x OP##= other.x; \
    y OP##= other.y; \
    z OP##= other.z; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR3_VECTOR3_OPERATOR_MACRO,Vector3,Vector3)

#define VECTOR3_VECTOR2_OPERATOR_MACRO(OP) {\
    x OP##= other.x; \
    y OP##= other.y; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR3_VECTOR2_OPERATOR_MACRO,Vector3,Vector2)

#define VECTOR3_FLOAT_OPERATOR_MACRO(OP) {\
    x OP##= other; \
    y OP##= other; \
    z OP##= other; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR3_FLOAT_OPERATOR_MACRO,Vector3,float)