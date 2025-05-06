//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_BLUR_H
#define CPP_HSE_BLUR_H

#pragma once

#include "../filter.h"

#include <cmath>
#include <numbers>

class Blur : public BaseFilter {
public:
    explicit Blur(double num) : sigma_{num} {};

public:
    Image Apply(Image& img) override;
    void ApplyBlurPass(Image& src, Image& dst, int kernel_radius, double sigma_sq, double normalizer,
                       bool horizontal) const;

protected:
    double sigma_;
};

#endif  // CPP_HSE_BLUR_H
