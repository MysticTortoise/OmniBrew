#pragma once

namespace OmniBrew::Math {
    class Color {
    public:
        float r = 0;
        float g = 0;
        float b = 0;
        float a = 1;
        Color(float r = 0, float g = 0, float b = 0, float a = 0);
    };
}