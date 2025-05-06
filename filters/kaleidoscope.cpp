//
// Created by Михаил  Мясников  on 06.05.2025.
//

#include "kaleidoscope.h"

Image Kaleidoscope::Apply(Image &img) {
    Image res(img.width, img.height);
    const double center_x = static_cast<double>(img.width) / 2.0;
    const double center_y = static_cast<double>(img.height) / 2.0;
    const double angle_per_sector = 2 * M_PI / sectors_;

    for (size_t y = 0; y < img.height; ++y) {
        for (size_t x = 0; x < img.width; ++x) {
            double dx = static_cast<double>(x) - center_x;
            double dy = static_cast<double>(y) - center_y;
            double r = std::sqrt(dx * dx + dy * dy);
            double theta = std::atan2(dy, dx);

            if (theta < 0) {
                theta += 2 * M_PI;
            }

            double sector_angle = std::fmod(theta, angle_per_sector);

            if (2.0 * sector_angle > angle_per_sector) {
                sector_angle = angle_per_sector - sector_angle;
            }

            double nx = center_x + r * std::cos(sector_angle);
            double ny = center_y + r * std::sin(sector_angle);

            int scr_x = std::clamp(static_cast<int>(std::round(nx)), 0, static_cast<int>(img.width) - 1);
            int scr_y = std::clamp(static_cast<int>(std::round(ny)), 0, static_cast<int>(img.height) - 1);

            res.colors[x][y] = img.colors[scr_x][scr_y];
        }
    }

    return res;
}
