//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "sharp.h"

static const int FIVE = 5.;

Image Sharp::Apply(Image& img) {
    Image res(img.width, img.height);
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            int red = 0;
            int blue = 0;
            int green = 0;
            for (std::pair<int, int> elem : INDEXES_TO_REPLACE) {
                size_t x = std::min(img.height - 1, j + elem.first);
                size_t y = std::min(img.width - 1, i + elem.second);
                red -= img.colors[x][y].red;
                blue -= img.colors[x][y].blue;
                green -= img.colors[x][y].green;
            }
            red += FIVE * img.colors[j][i].red;
            blue += FIVE * img.colors[j][i].blue;
            green += FIVE * img.colors[j][i].green;
            red = std::clamp(red, MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            blue = std::clamp(blue, MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            green = std::clamp(green, MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            res.colors[j][i].red = red;
            res.colors[j][i].green = green;
            res.colors[j][i].blue = blue;
        }
    }
    return res;
}
