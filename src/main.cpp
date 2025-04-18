#include <iostream>
#include <string>
#include <fmt/core.h>
#include <cstdint>
#include <fmt/color.h>

#include "read.h"
#include "validation.h"
#include "art.h"
#include "search.h"
#include "init.h"


int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        bool exit{false};
        art::displayGraphic();
        std::int64_t renderCount {};
        do {
            renderCount++;
            std::string buffer = init::display(renderCount);
            const std::int16_t choice = validation::choiceKey(
                buffer, search::VALID_RANGE[0],
                search::VALID_RANGE[1]
            );
            validation::clearTerminal();
            search::ROUTE r = search::router(choice);

            switch (r) {
                case search::ROUTE::EXIT_PROGRAM:
                    exit = true;
                    break;
                case search::ROUTE::CONTINUE:
                    break;
                case search::ROUTE::SEARCH_TEXT_FILE:

                    break;
                default:
                    exit = false;
                    break;
            }
        }
        while (!exit);
    }
    else {
        // argv logic
    }
    return 0;
}
