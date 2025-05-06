//
// Created by Михаил  Мясников  on 06.05.2025.
//

#ifndef IMAGE_PROC_FILTER_FACTORY_H
#define IMAGE_PROC_FILTER_FACTORY_H


#include "filters/blur.h"
#include "filters/crop.h"
#include "filters/edge.h"
#include "filters/gs.h"
#include "filters/neg.h"
#include "filters/sepia.h"
#include "filters/sharp.h"
#include "filters/kaleidoscope.h"
#include "cmd_line_args_parser.h"
#include "filter.h"

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class FilterFactory {
public:
    static std::unique_ptr<BaseFilter> CreateFilter(const FilterDescriptor& fd);
};


#endif //IMAGE_PROC_FILTER_FACTORY_H
