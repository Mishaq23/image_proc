//
// Created by Михаил  Мясников  on 27.03.2025.
//

#ifndef CPP_HSE_APPLY_FILTERS_H
#define CPP_HSE_APPLY_FILTERS_H

#include <stdexcept>
#include <memory>

#include "image.h"
#include "filter.h"
#include "cmd_line_args_parser.h"
#include "filters/blur.h"
#include "filters/crop.h"
#include "filters/edge.h"
#include "filters/gs.h"
#include "filters/neg.h"
#include "filters/sepia.h"
#include "filters/sharp.h"

std::unique_ptr<Blur> MakeBlur(const FilterDescriptor* fd);
std::unique_ptr<Crop> MakeCrop(const FilterDescriptor* fd);
std::unique_ptr<Edge> MakeEdge(const FilterDescriptor* fd);
std::unique_ptr<Gs> MakeGs(const FilterDescriptor* fd);
std::unique_ptr<Neg> MakeNeg(const FilterDescriptor* fd);
std::unique_ptr<Sepia> MakeSepia(const FilterDescriptor* fd);
std::unique_ptr<Sharp> MakeSharp(const FilterDescriptor* fd);

class ApplyFilters {
public:
    ApplyFilters() = default;

public:
    bool Apply(const CmdLineArgsParser::FilterDescriptors& descriptors, Image& img);
};

#endif  // CPP_HSE_APPLY_FILTERS_H
