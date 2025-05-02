#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include "init.hpp"

std::string init::display(const std::int64_t reRenderCount) {
    fmt::print("\n\n");
    if (reRenderCount > 1) {
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "> Choose one of the options below. ({})\n\n",
            VERSION
        );
    } else {
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "> Welcome! Choose one of the options below. ({})\n\n",
            VERSION
        );
    }
    fmt::print("Provide the number to the left of the option as input.");
    fmt::print(
        fmt::emphasis::bold,
        " Ex: 1\n\n"
    );
    fmt::print("========================================\n");
    fmt::print("========================================\n");
    fmt::print("\n");
    fmt::print(
        fg(fmt::color::green) | fmt::emphasis::bold |
        fmt::emphasis::underline,
        "Options:\n\n"
    );
    fmt::print("1. Exit {}\n", "🎉\n");
    fmt::print("2. Search Text File {}\n", "📁\n");
    fmt::print("\n");
    fmt::print("========================================\n");
    fmt::print("========================================\n\n");

    fmt::print("Provide Input Here: ");
    std::string buffer{};
    std::cin >> buffer;
    return buffer;
}
