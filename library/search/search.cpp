#include <fmt/core.h>
#include <fmt/color.h>
#include <fstream>

#include "search.h"

namespace search {
    ROUTE router(const std::int16_t key) {
        if (key == -2) {
            fmt::print(
                fg(fmt::color::crimson) | fmt::emphasis::bold,
                "> Your previous choice was invalid.\n"
            );
            fmt::print(
                fg(fmt::color::crimson) | fmt::emphasis::bold,
               "> The option you selected is not available. Try again! 👍\n"
            );
            return ROUTE::CONTINUE;
        } else if (key == -1) {
            fmt::print(
                fg(fmt::color::crimson) | fmt::emphasis::bold,
                "> Your previous choice was invalid.\n"
            );
            fmt::print(
               fg(fmt::color::crimson) | fmt::emphasis::bold,
              "> The option you selected is not a valid positive number. Try again! 👍\n"
           );
            return ROUTE::CONTINUE;
        } else if (key == 1) {
            return ROUTE::EXIT_PROGRAM;
        } else if (key == 2) {
            return ROUTE::SEARCH_TEXT_FILE;
        }
        return ROUTE::CONTINUE;
    }
    // std::vector<std::vector<std::string>> search::readFile(std::string file) {
    //     // std::ifstream ifFile(file);
    //     // ifFile.open(file);
    //     return std::vector<std::vector<std::string>> v{{"1"}};
    // }
}