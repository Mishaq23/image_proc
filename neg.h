//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_NEG_H
#define CPP_HSE_NEG_H

#include "../filter.h"

class Neg : public BaseFilter {
public:
    Neg() = default;

public:
    Image Apply(Image& img) override;
};

#endif  // CPP_HSE_NEG_H
