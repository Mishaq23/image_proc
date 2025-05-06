//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "../filter.h"
#include "gs.h"

Image Gs::Apply(Image& img) {
    for (size_t i = 0; i < img.width; ++i) {
        for (size_t j = 0; j < img.height; ++j) {
            unsigned char r = img.colors[j][i].red;
            unsigned char g = img.colors[j][i].green;
            unsigned char b = img.colors[j][i].blue;
            unsigned char now_color =
                std::clamp(static_cast<int>(R * r + G * g + B * b), MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            img.colors[j][i].red = now_color;
            img.colors[j][i].green = now_color;
            img.colors[j][i].blue = now_color;
        }
    }
    return img;
}
