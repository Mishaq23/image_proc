//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "blur.h"

static constexpr double TwoPi = 2.0 * std::numbers::pi;

Image Blur::Apply(Image& img) {
    const double sigma_sq = sigma_ * sigma_;
    const int kernel_radius = static_cast<int>(3 * sigma_);

    std::vector<double> kernel(2 * kernel_radius + 1);
    double weight_sum = 0.0;
    for (int i = -kernel_radius; i <= kernel_radius; ++i) {
        double w = std::exp(-(i * i) / (2.0 * sigma_sq));
        kernel[i + kernel_radius] = w;
        weight_sum += w;
    }
    for (double& w : kernel) {
        w /= weight_sum;
    }

    Image temp_img(img.width, img.height);
    Image result_img(img.width, img.height);

    ApplyBlurPass(img, temp_img, kernel_radius, kernel, true);

    ApplyBlurPass(temp_img, result_img, kernel_radius, kernel, false);

    return result_img;
}

void Blur::ApplyBlurPass(Image& src, Image& dst, int kernel_radius,
                         const std::vector<double>& kernel, bool horizontal) const {
    const int width = static_cast<int>(src.width);
    const int height = static_cast<int>(src.height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double r = 0.0, g = 0.0, b = 0.0;

            for (int i = -kernel_radius; i <= kernel_radius; ++i) {
                int src_x = horizontal ? std::clamp(x + i, 0, width - 1) : x;
                int src_y = horizontal ? y : std::clamp(y + i, 0, height - 1);

                const Color& c = src.colors[src_x][src_y];
                double weight = kernel[i + kernel_radius];

                r += c.red * weight;
                g += c.green * weight;
                b += c.blue * weight;
            }

            dst.colors[x][y].red = static_cast<unsigned char>(std::clamp(std::round(r), 0.0, 255.0));
            dst.colors[x][y].green = static_cast<unsigned char>(std::clamp(std::round(g), 0.0, 255.0));
            dst.colors[x][y].blue = static_cast<unsigned char>(std::clamp(std::round(b), 0.0, 255.0));
        }
    }
}
