//
// Created by Михаил  Мясников  on 28.03.2025.
//

#include "color.h"

bool Color::operator==(const Color &rhs) const {
    return (red == rhs.red && green == rhs.green && blue == rhs.blue);
}

bool Color::operator!=(const Color &rhs) const {
    return !(*this == rhs);
}
