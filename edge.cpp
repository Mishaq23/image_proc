//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "edge.h"
#include "gs.h"

Image Edge::Apply(Image& img) {
    Image res(img.width, img.height);
    Gs grayscale;
    res = grayscale.Apply(img);
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            int64_t color = 0;
            for (std::pair<int, int> elem : INDEXES_TO_REPLACE) {
                size_t x = std::min(img.height - 1, j + elem.first);
                size_t y = std::min(img.width - 1, i + elem.second);
                color -= img.colors[x][y].blue;
            }
            color += 4 * img.colors[j][i].blue;
            if (color > static_cast<int64_t>(threshold_ * MAX_RGB_VALUE_INT)) {
                res.colors[j][i].red = MAX_RGB_VALUE_CHAR;
                res.colors[j][i].green = MAX_RGB_VALUE_CHAR;
                res.colors[j][i].blue = MAX_RGB_VALUE_CHAR;
            } else {
                res.colors[j][i].red = MIN_RGB_VALUE_CHAR;
                res.colors[j][i].green = MIN_RGB_VALUE_CHAR;
                res.colors[j][i].blue = MIN_RGB_VALUE_CHAR;
            }
        }
    }
    return res;
}
