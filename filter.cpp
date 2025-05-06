//
// Created by Михаил  Мясников  on 25.03.2025.
//

#include "filter.h"

Image BaseFilter::Apply(Image& img) {
    return img;
}

Image BaseFilter::Apply(const Image& img) const {
    return Image();
}
