#pragma once

#include "OmniBrew/Math/Vector2.hpp"
#include "OmniBrew/Math/Vector3.hpp"

namespace OmniBrew::Core::GraphicsCore{
    class Shader{
        void setParameter(const char* parameterName, bool value);
        void setParameter(const char* parameterName, int value);
        void setParameter(const char* parameterName, float value);
        void setParameter(const char* parameterName, Math::Vector2 value);
        void setParameter(const char* parameterName, Math::Vector3 value);
    };
}