//
// Created by Михаил  Мясников  on 27.03.2025.
//

#ifndef CPP_HSE_SEPIA_H
#define CPP_HSE_SEPIA_H

#include "../filter.h"

class Sepia : public BaseFilter {
public:
    explicit Sepia() = default;

public:
    Image Apply(Image& img) override;
};

#endif  // CPP_HSE_SEPIA_H
