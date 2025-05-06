//
// Created by Михаил  Мясников  on 27.03.2025.
//

#include "sepia.h"

// constants for red color
static const double RED1 = 0.393;
static const double RED2 = 0.769;
static const double RED3 = 0.189;

// constants for green color
static const double GREEN1 = 0.349;
static const double GREEN2 = 0.686;
static const double GREEN3 = 0.168;

// constants for blue color
static const double BLUE1 = 0.272;
static const double BLUE2 = 0.534;
static const double BLUE3 = 0.131;

Image Sepia::Apply(Image& image) {
    for (size_t y = 0; y < image.height; ++y) {
        for (size_t x = 0; x < image.width; ++x) {
            Color c = image.colors[x][y];
            unsigned char r = std::clamp(static_cast<int>(RED1 * c.red + RED2 * c.green + RED3 * c.blue),
                                         MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            unsigned char g = std::clamp(static_cast<int>(GREEN1 * c.red + GREEN2 * c.green + GREEN3 * c.blue),
                                         MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            unsigned char b = std::clamp(static_cast<int>(BLUE1 * c.red + BLUE2 * c.green + BLUE3 * c.blue),
                                         MIN_RGB_VALUE_INT, MAX_RGB_VALUE_INT);
            image.colors[x][y].red = static_cast<uint8_t>(std::clamp(r, MIN_RGB_VALUE_CHAR, MAX_RGB_VALUE_CHAR));
            image.colors[x][y].green = static_cast<uint8_t>(std::clamp(g, MIN_RGB_VALUE_CHAR, MAX_RGB_VALUE_CHAR));
            image.colors[x][y].blue = static_cast<uint8_t>(std::clamp(b, MIN_RGB_VALUE_CHAR, MAX_RGB_VALUE_CHAR));
        }
    }
    return image;
}
