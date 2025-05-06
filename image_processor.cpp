#include "apply_filters.h"
#include "bmp.h"
#include "image.h"
#include "cmd_line_args_parser.h"

int main(int argc, char** argv) {
    BMP file;
    Image img;
    CmdLineArgsParser parser;
    ApplyFilters controller;
    CmdLineArgsParser::ErrorCode code = parser.Parse(argc, argv);
    if (code == CmdLineArgsParser::ErrorCode::Ok) {
        file.ReadImage(img, parser.GetInFileName());
        controller.Apply(parser.GetFilterDescriptors(), img);
        file.WriteImage(img, parser.GetOutFileName());
    }
}
