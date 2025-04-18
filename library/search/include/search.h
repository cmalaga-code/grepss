#ifndef SEARCH_H
#define SEARCH_H

#include <cstdint>
#include <vector>


namespace search {
    enum class ROUTE {
        CONTINUE,
        EXIT_PROGRAM,
        SEARCH_TEXT_FILE,
    };
    constexpr std::uint8_t VALID_RANGE[2]{1, 2};
    ROUTE router(std::int16_t key);
    // std::vector<std::vector<std::string>> readFile(std::string file);
}

#endif //SEARCH_H
