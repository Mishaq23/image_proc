#include "cmd_line_args_parser.h"

CmdLineArgsParser::ErrorCode CmdLineArgsParser::Parse(int argc, char *argv[]) {
    if (argc < MIN_ARG_COUNT) {
        return ErrorCode::NotEnoughArgs;
    }

    in_file_name_ = argv[INPUT_INDEX_CMD];
    out_file_name_ = argv[OUTPUT_INDEX_CMD];

    for (int i = MIN_ARG_COUNT; i < argc; ++i) {
        if (*argv[i] == '-') {
            FilterDescriptor filter;
            filter.filter_name = std::string(argv[i]).substr(1);
            filter_descriptors_.push_back(filter);
        } else {
            filter_descriptors_.back().filter_params.emplace_back(argv[i]);
        }
    }

    return ErrorCode::Ok;
}
