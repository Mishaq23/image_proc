//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_EDGE_H
#define CPP_HSE_EDGE_H

#include "../filter.h"

class Edge : public BaseFilter {
public:
    explicit Edge(double num) : threshold_{num} {};

public:
    Image Apply(Image& img) override;

protected:
    double threshold_;
};

#endif  // CPP_HSE_EDGE_H
