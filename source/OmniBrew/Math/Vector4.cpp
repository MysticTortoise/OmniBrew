#include "OmniBrew/Math/Vector4.hpp"
#include "OmniBrew/Math/MathMacros.hpp"

using namespace OmniBrew::Math;


Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

#define VECTOR4_FLOAT_OPERATOR_MACRO(OP) {\
    x OP##= other; \
    y OP##= other; \
    z OP##= other; \
    w OP##= other; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR4_FLOAT_OPERATOR_MACRO, Vector4, float)

// Yes, this is stupid. Still better than writing the same fucking operator overload 50 billion times!!

#define VECTOR4_VECTOR2_OPERATOR_MACRO(OP) {\
    x OP##= other.x; \
    y OP##= other.y; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR4_VECTOR2_OPERATOR_MACRO, Vector4, Vector2)

#define VECTOR4_VECTOR3_OPERATOR_MACRO(OP) {\
    x OP##= other.x; \
    y OP##= other.y; \
    z OP##= other.z; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR4_VECTOR3_OPERATOR_MACRO, Vector4, Vector3)

#define VECTOR4_VECTOR4_OPERATOR_MACRO(OP) {\
    x OP##= other.x; \
    y OP##= other.y; \
    z OP##= other.z; \
    w OP##= other.w; \
    return *this; \
};
SOURCE_MATH_MACRO(VECTOR4_VECTOR4_OPERATOR_MACRO, Vector4, Vector4)

