#pragma once

#include <SDL3/SDL.h>

class Color {
public:
    Uint8 r, g, b, a;

    Color(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 255)
        : r(r), g(g), b(b), a(a) {
    }
};