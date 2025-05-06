//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_IMAGE_H
#define CPP_HSE_IMAGE_H

#pragma once

#include <vector>

#include "color.h"

struct Image {
    size_t width;
    size_t height;

    std::vector<std::vector<Color> > colors;

    explicit Image() : width(0), height(0){};

    Image(size_t w, size_t h);

    bool operator==(const Image& other) const;
};

#endif  // CPP_HSE_IMAGE_H
