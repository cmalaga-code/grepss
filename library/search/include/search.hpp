#ifndef SEARCH_H
#define SEARCH_H

#include <cstdint>
#include <utility>

namespace search {
    enum class ROUTE {
        CONTINUE,
        EXIT_PROGRAM,
        SEARCH_TEXT_FILE,
    };
    constexpr std::uint8_t VALID_RANGE[2]{1, 2};
    ROUTE router(std::int16_t key);
    void searchFile();
    void argCommands(const char* argv[], const int& argc);
}

#endif //SEARCH_H
