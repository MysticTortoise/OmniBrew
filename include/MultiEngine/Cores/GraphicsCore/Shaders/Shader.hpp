#pragma once

#include "MultiEngine/Math/Vector2.hpp"
#include "MultiEngine/Math/Vector3.hpp"

namespace MultiEngine::Core::GraphicsCore{
    class Shader{
        void setParameter(const char* parameterName, bool value);
        void setParameter(const char* parameterName, int value);
        void setParameter(const char* parameterName, float value);
        void setParameter(const char* parameterName, Math::Vector2 value);
        void setParameter(const char* parameterName, Math::Vector3 value);
    };
}