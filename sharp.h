//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_SHARP_H
#define CPP_HSE_SHARP_H

#include "../filter.h"

class Sharp : public BaseFilter {
public:
    explicit Sharp() = default;

public:
    Image Apply(Image& img) override;

protected:
};

#endif  // CPP_HSE_SHARP_H
