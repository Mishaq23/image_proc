//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_FILTER_H
#define CPP_HSE_FILTER_H

#include "image.h"

#include <algorithm>
#include <utility>
#include <vector>

const unsigned char MAX_RGB_VALUE_CHAR = 255;
const unsigned char MIN_RGB_VALUE_CHAR = 0;
const int MAX_RGB_VALUE_INT = 255;
const int MIN_RGB_VALUE_INT = 0;
const std::vector<std::pair<int, int>> INDEXES_TO_REPLACE = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class BaseFilter {
public:
    virtual ~BaseFilter() = default;

public:
    virtual Image Apply(Image& img);
    virtual Image Apply(const Image& img) const;
};

#endif  // CPP_HSE_FILTER_H
