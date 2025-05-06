//
// Created by Михаил  Мясников  on 27.03.2025.
//

#include "apply_filters.h"

std::unique_ptr<Blur> MakeBlur(const FilterDescriptor* fd) {
    if (fd->GetFilterParamsCount() == 0) {
        throw std::logic_error("Invalid filter parameters count.");
    }

    double gauss_param = std::stod(fd->filter_params[0]);
    return std::unique_ptr<Blur>(new Blur(gauss_param));
}

std::unique_ptr<Crop> MakeCrop(const FilterDescriptor* fd) {
    if (fd->GetFilterParamsCount() < 2) {
        throw std::logic_error("Invalid filter parameters count.");
    }

    size_t width = static_cast<size_t>(std::stold(fd->filter_params[0]));
    size_t height = static_cast<size_t>(std::stold(fd->filter_params[1]));
    return std::unique_ptr<Crop>(new Crop(width, height));
}

std::unique_ptr<Edge> MakeEdge(const FilterDescriptor* fd) {
    if (fd->GetFilterParamsCount() == 0) {
        throw std::logic_error("Invalid filter parameters count.");
    }

    double threshold = std::stod(fd->filter_params[0]);
    return std::unique_ptr<Edge>(new Edge(threshold));
}

std::unique_ptr<Gs> MakeGs(const FilterDescriptor* fd) {
    return std::unique_ptr<Gs>(new Gs());
}

std::unique_ptr<Neg> MakeNeg(const FilterDescriptor* fd) {
    return std::unique_ptr<Neg>(new Neg());
}

std::unique_ptr<Sepia> MakeSepia(const FilterDescriptor* fd) {
    return std::unique_ptr<Sepia>(new Sepia());
}

std::unique_ptr<Sharp> MakeSharp(const FilterDescriptor* fd) {
    return std::unique_ptr<Sharp>(new Sharp());
}

bool ApplyFilters::Apply(const CmdLineArgsParser::FilterDescriptors& descriptors, Image& img) {
    for (const FilterDescriptor& fd : descriptors) {
        if (fd.filter_name == "blur") {
            std::unique_ptr<Blur> filter(MakeBlur(&fd));
            filter->Apply(img);
        } else if (fd.filter_name == "crop") {
            std::unique_ptr<Crop> filter(MakeCrop(&fd));
            img = filter->Apply(img);
        } else if (fd.filter_name == "edge") {
            std::unique_ptr<Edge> filter(MakeEdge(&fd));
            img = filter->Apply(img);
        } else if (fd.filter_name == "gs") {
            std::unique_ptr<Gs> filter(MakeGs(&fd));
            filter->Apply(img);
        } else if (fd.filter_name == "neg") {
            std::unique_ptr<Neg> filter(MakeNeg(&fd));
            filter->Apply(img);
        } else if (fd.filter_name == "sepia") {
            std::unique_ptr<Sepia> filter(MakeSepia(&fd));
            filter->Apply(img);
        } else if (fd.filter_name == "sharp") {
            std::unique_ptr<Sharp> filter(MakeSharp(&fd));
            img = filter->Apply(img);
        } else {
            throw std::logic_error("Invalid filter name.");
        }
    }
    return true;
}
