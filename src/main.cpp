#include <iostream>
#include <string>
#include <fmt/core.h>
#include <cstdint>
#include <fmt/color.h>

#include "validation.hpp"
#include "art.hpp"
#include "search.hpp"
#include "init.hpp"
#include "clear.hpp"


int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        bool exit {false};
        art::displayGraphic();
        std::int64_t renderCount {};
        do {
            renderCount++;
            std::string userChoice = init::display(renderCount);
            const std::int16_t choice = validation::choiceKey(
                userChoice, search::VALID_RANGE[0],
                search::VALID_RANGE[1]
            );
            clearTerminal();
            search::ROUTE r = search::router(choice);

            switch (r) {
            case search::ROUTE::EXIT_PROGRAM:
                exit = true;
                break;
            case search::ROUTE::CONTINUE:
                break;
            case search::ROUTE::SEARCH_TEXT_FILE:
                search::searchFile();
                break;
            default:
                exit = false;
                break;
            }
        }
        while (!exit);
    }
    else {
        search::argCommands(argv, argc);
    }
    return 0;
}
