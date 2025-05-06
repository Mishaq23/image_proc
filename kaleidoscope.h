//
// Created by Михаил  Мясников  on 06.05.2025.
//

#ifndef IMAGE_PROC_KALEIDOSCOPE_H
#define IMAGE_PROC_KALEIDOSCOPE_H

#include <cmath>

#include "../image.h"
#include "../filter.h"


class Kaleidoscope : public BaseFilter {
public:
    explicit Kaleidoscope(int sectors = 6) : sectors_{sectors} {}
    Image Apply(Image& img) override;

private:
    int sectors_;

};


#endif //IMAGE_PROC_KALEIDOSCOPE_H
