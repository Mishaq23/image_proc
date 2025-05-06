//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_CROP_H
#define CPP_HSE_CROP_H

#include "../filter.h"

#include <algorithm>

class Crop : public BaseFilter {
public:
    Crop() = default;
    Crop(size_t width, size_t height);

public:
    Image Apply(Image& img) override;

protected:
    size_t width_;
    size_t height_;
};

#endif  // CPP_HSE_CROP_H
