//
// Created by Михаил  Мясников  on 28.03.2025.
//

#ifndef CPP_HSE_COLOR_H
#define CPP_HSE_COLOR_H

#include <cstdint>

using Byte = unsigned char;

struct Color {
    Byte red;
    Byte green;
    Byte blue;

    bool operator==(const Color& rhs) const;
    bool operator!=(const Color& rhs) const;
};

#endif  // CPP_HSE_COLOR_H
