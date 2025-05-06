//
// Created by Михаил  Мясников  on 25.03.2025.
//

#ifndef CPP_HSE_BMP_H
#define CPP_HSE_BMP_H

#pragma once

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>

#include "image.h"

const int BMPFILETYPE = 0x4D42;

#pragma pack(push, 1)
struct FileHeader {
    uint16_t Typ = {BMPFILETYPE};
    uint32_t Size = 0;
    uint16_t Reserved1 = 0;
    uint16_t Reserved2 = 0;
    uint32_t Offset = 0;
};

struct InfoHeader {
    uint32_t HeaderSize;
    int32_t Width;
    int32_t Height;
    int32_t HorizontalPixPerMeter;
    int32_t VerticalPixPerMeter;
    uint32_t ColorsNum;
    uint32_t ColorsImportant;
    uint16_t Planes;
    uint16_t Bits;
    uint32_t Compression;
    uint32_t SizeRaw;
};
#pragma pack(pop)

class BMP {
private:
    void UpdateHeaders(size_t width, size_t height);

public:
    FileHeader file_header;
    InfoHeader info_header;

    void ReadImage(Image& image, const std::string& file_name);

    void WriteImage(const Image& image, const std::string& file_name);
};

#endif  // CPP_HSE_BMP_H
