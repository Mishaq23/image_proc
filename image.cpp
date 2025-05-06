//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "image.h"

Image::Image(size_t w, size_t h) : width(w), height(h) {
    colors.resize(height, std::vector<Color>(width));
}

bool Image::operator==(const Image& other) const {
    if (width != other.width || height != other.height) {
        return false;
    }

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (colors[i][j] != other.colors[i][j]) {
                return false;
            }
        }
    }

    return true;
}
