//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "crop.h"

Crop::Crop(size_t width, size_t height) : width_{width}, height_{height} {
}

Image Crop::Apply(Image& img) {
    width_ = std::min(width_, img.width);
    height_ = std::min(height_, img.height);
    Image res(width_, height_);
    for (size_t i = 0; i < res.width; ++i) {
        for (size_t j = 0; j < res.height; ++j) {
            res.colors[j][i] = img.colors[j][i];
        }
    }
    return res;
}
