//
// Created by Михаил  Мясников  on 27.03.2025.
//

#ifndef CPP_HSE_APPLY_FILTERS_H
#define CPP_HSE_APPLY_FILTERS_H

#include <stdexcept>
#include <memory>

#include "filter_factory.h"

class ApplyFilters {
public:
    ApplyFilters() = default;

public:
    bool Apply(const CmdLineArgsParser::FilterDescriptors& descriptors, Image& img);
};

#endif  // CPP_HSE_APPLY_FILTERS_H
