//
// Created by Михаил  Мясников  on 28.03.2025.
//

#include "bmp.h"

void BMP::UpdateHeaders(size_t width, size_t height) {
    info_header.Width = static_cast<int32_t>(width);
    info_header.Height = static_cast<int32_t>(height);

    size_t bytes_per_line = ((width * 3 + 3) / 4) * 4;
    info_header.SizeRaw = static_cast<uint32_t>(bytes_per_line * height);
    file_header.Size = info_header.SizeRaw + file_header.Offset;
}

void BMP::ReadImage(Image& image, const std::string& file_name) {
    std::ifstream file(file_name, std::ios::binary);
    if (!file) {
        throw std::invalid_argument("There is something wrong with the image, can't read.");
    }

    file.read(reinterpret_cast<char*>(&file_header), sizeof(FileHeader));
    file.read(reinterpret_cast<char*>(&info_header), sizeof(InfoHeader));
    file.seekg(file_header.Offset, file.beg);

    image.width = info_header.Width;
    image.height = info_header.Height;
    image.colors.resize(image.height, std::vector<Color>(image.width));
    size_t bytes_per_line = ((image.width * 3 + 3) / 4) * 4;
    std::vector<Byte> line(bytes_per_line);

    for (size_t i = image.height - 1; i != -1; --i) {
        file.read(reinterpret_cast<char*>(line.data()), static_cast<int64_t>(bytes_per_line));
        for (size_t j = 0; j < image.width; ++j) {
            image.colors[i][j].blue = line[j * 3];
            image.colors[i][j].green = line[j * 3 + 1];
            image.colors[i][j].red = line[j * 3 + 2];
        }
    }
    file.close();
}

void BMP::WriteImage(const Image& image, const std::string& file_name) {
    UpdateHeaders(image.width, image.height);

    std::ofstream file(file_name, std::ios::binary);
    if (!file) {
        throw std::invalid_argument("There is something wrong with the image, can't write.");
    }
    file.write(reinterpret_cast<char*>(&file_header), sizeof(FileHeader));
    file.write(reinterpret_cast<char*>(&info_header), sizeof(InfoHeader));

    size_t bytes_per_line = ((image.width * 3 + 3) / 4) * 4;
    std::vector<unsigned char> line(bytes_per_line);

    for (size_t i = image.height - 1; i != -1; --i) {
        for (size_t j = 0; j < image.width; ++j) {
            line[j * 3 + 2] = image.colors[i][j].red;
            line[j * 3 + 1] = image.colors[i][j].green;
            line[j * 3] = image.colors[i][j].blue;
        }
        file.write(reinterpret_cast<char*>(line.data()), static_cast<int64_t>(bytes_per_line));
    }
    file.close();
}
