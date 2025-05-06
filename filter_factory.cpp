//
// Created by Михаил  Мясников  on 06.05.2025.
//

#include "filter_factory.h"

using FilterCreator = std::function<std::unique_ptr<BaseFilter>(const FilterDescriptor&)>;

std::unique_ptr<BaseFilter> FilterFactory::CreateFilter(const FilterDescriptor& fd) {
    static const std::unordered_map<std::string, FilterCreator> registry = {
            {"blur", [](const FilterDescriptor& fd) {
                if (fd.GetFilterParamsCount() == 0) {
                    throw std::logic_error("Missing blur param");
                }
                return std::make_unique<Blur>(std::stod(fd.filter_params[0]));
            }},
            {"crop", [](const FilterDescriptor& fd) {
                if (fd.GetFilterParamsCount() < 2) {
                    throw std::logic_error("Missing crop params");
                }
                size_t w = std::stoul(fd.filter_params[0]);
                size_t h = std::stoul(fd.filter_params[1]);
                return std::make_unique<Crop>(w, h);
            }},
            {"edge", [](const FilterDescriptor& fd) {
                if (fd.GetFilterParamsCount() == 0) {
                    throw std::logic_error("Missing edge param");
                }
                return std::make_unique<Edge>(std::stod(fd.filter_params[0]));
            }},
            {"gs", [](const FilterDescriptor&) {
                return std::make_unique<Gs>();
            }},
            {"neg", [](const FilterDescriptor&) {
                return std::make_unique<Neg>();
            }},
            {"sepia", [](const FilterDescriptor&) {
                return std::make_unique<Sepia>();
            }},
            {"sharp", [](const FilterDescriptor&) {
                return std::make_unique<Sharp>();
            }},
            {"kaleidoscope", [](const FilterDescriptor& fd) {
                if (fd.GetFilterParamsCount() > 1) {
                    throw std::logic_error("Too many params for kaleidoscope");
                } else if (fd.GetFilterParamsCount() == 1) {
                    int sectors = std::stoi(fd.filter_params[0]);
                    return std::make_unique<Kaleidoscope>(sectors);
                }
                return std::make_unique<Kaleidoscope>();
            }}
    };

    auto it = registry.find(fd.filter_name);
    if (it == registry.end()) {
        throw std::logic_error("Unknown filter: " + fd.filter_name);
    }

    return it->second(fd);
}
