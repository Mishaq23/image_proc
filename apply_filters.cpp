//
// Created by Михаил  Мясников  on 27.03.2025.
//

#include "apply_filters.h"

#include <memory>

bool ApplyFilters::Apply(const CmdLineArgsParser::FilterDescriptors& descriptors, Image& img) {
    for (const FilterDescriptor& fd : descriptors) {
        std::unique_ptr<BaseFilter> filter = FilterFactory::CreateFilter(fd);
        img = filter->Apply(img);
    }
    return true;
}
