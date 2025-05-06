//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "sharp.h"

static const int FIVE = 5.;

Image Sharp::Apply(Image& img) {
    Image res(img.width, img.height);

    for (size_t y = 0; y < img.height; ++y) {
        for (size_t x = 0; x < img.width; ++x) {
            int r = 0, g = 0, b = 0;

            for (const std::pair<int, int>& offset : INDEXES_TO_REPLACE) {
                int nx = static_cast<int>(x) + offset.first;
                int ny = static_cast<int>(y) + offset.second;

                nx = std::clamp(nx, 0, static_cast<int>(img.width) - 1);
                ny = std::clamp(ny, 0, static_cast<int>(img.height) - 1);

                const Color& c = img.colors[nx][ny];
                r -= c.red;
                g -= c.green;
                b -= c.blue;
            }

            const Color& center = img.colors[x][y];
            r += 5 * center.red;
            g += 5 * center.green;
            b += 5 * center.blue;

            res.colors[x][y].red = static_cast<unsigned char>(std::clamp(r, 0, 255));
            res.colors[x][y].green = static_cast<unsigned char>(std::clamp(g, 0, 255));
            res.colors[x][y].blue = static_cast<unsigned char>(std::clamp(b, 0, 255));
        }
    }

    return res;
}
