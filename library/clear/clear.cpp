#include <iostream>
#include "clear.hpp"

void clearTerminal() {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}