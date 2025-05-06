//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "neg.h"

Image Neg::Apply(Image& img) {
    for (size_t i = 0; i < img.width; ++i) {
        for (size_t j = 0; j < img.height; ++j) {
            img.colors[j][i].red = MAX_RGB_VALUE_CHAR - img.colors[j][i].red;
            img.colors[j][i].green = MAX_RGB_VALUE_CHAR - img.colors[j][i].green;
            img.colors[j][i].blue = MAX_RGB_VALUE_CHAR - img.colors[j][i].blue;
        }
    }
    return img;
}
