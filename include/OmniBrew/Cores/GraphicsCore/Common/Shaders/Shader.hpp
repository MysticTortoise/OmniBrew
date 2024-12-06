#pragma once

#include "OmniBrew/Math/Vector2.hpp"
#include "OmniBrew/Math/Vector3.hpp"
#include "OmniBrew/Math/Vector4.hpp"
#include "OmniBrew/Math/Color.hpp"


namespace OmniBrew::Core::GraphicsCore{

    class Shader{
        public:
        void setParameter(const char* parameterName, bool value);
        void setParameter(const char* parameterName, int value);
        void setParameter(const char* parameterName, float value);
        void setParameter(const char* parameterName, Math::Vector2 value);
        void setParameter(const char* parameterName, Math::Vector3 value);
        void setParameter(const char* parameterName, Math::Vector4 value);
        void setParameter(const char* parameterName, Math::Color value);

        void use();
    };
}