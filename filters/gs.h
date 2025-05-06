//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_GS_H
#define CPP_HSE_GS_H

#include "../filter.h"

static const double R = 0.299;
static const double G = 0.587;
static const double B = 0.114;

class Gs : public BaseFilter {
public:
    Gs() = default;

public:
    Image Apply(Image& img) override;
};

#endif  // CPP_HSE_GS_H
