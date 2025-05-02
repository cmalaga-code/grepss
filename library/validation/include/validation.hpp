#ifndef VALIDATION_H
#define VALIDATION_H

#include <cstdint>

namespace validation {
    std::int16_t choiceKey(const std::string& input, std::uint16_t choiceStartRange, std::uint16_t choiceEndRange);
}

#endif //VALIDATION_H
