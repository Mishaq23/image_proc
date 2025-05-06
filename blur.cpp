//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "blur.h"

static constexpr double TwoPi = 2.0 * std::numbers::pi;

Image Blur::Apply(Image& img) {
    const double sigma_sq = sigma_ * sigma_;
    const double normalizer = 1.0 / (std::sqrt(TwoPi * sigma_sq));
    const int kernel_radius = static_cast<int>(3 * sigma_);

    Image img_copy = img;
    Image temp_img(img.width, img.height);

    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            temp_img.colors[j][i] = img.colors[j][i];
        }
    }

    ApplyBlurPass(img_copy, temp_img, kernel_radius, sigma_sq, normalizer, true);
    ApplyBlurPass(temp_img, img_copy, kernel_radius, sigma_sq, normalizer, false);

    return temp_img;
}

void Blur::ApplyBlurPass(Image& src, Image& dst, int kernel_radius, double sigma_sq, double normalizer,
                         bool horizontal) const {
    const int width = static_cast<int>(src.width);
    const int height = static_cast<int>(src.height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Color accum{};

            for (int i = -kernel_radius; i <= kernel_radius; ++i) {
                const int src_x = horizontal ? std::clamp(x + i, 0, width - 1) : x;
                const int src_y = horizontal ? y : std::clamp(y + i, 0, height - 1);

                const double weight = normalizer * std::exp(-(i * i) / (2 * sigma_sq));

                Color c = src.colors[src_x][src_y];
                accum.red += std::clamp(static_cast<int>(c.red * weight), MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
                accum.green += std::clamp(static_cast<int>(c.green * weight), MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
                accum.blue += std::clamp(static_cast<int>(c.blue * weight), MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            }

            dst.colors[x][y] = accum;
        }
    }
}