#ifndef INIT_H
#define INIT_H

#include <string>
#include <cstdint>

namespace init {
    constexpr std::string VERSION = "v0.1.0";
    std::string display(std::int64_t reRenderCount);
}

#endif //INIT_H
