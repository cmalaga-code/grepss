#include <fmt/core.h>
#include <sstream>
#include <fmt/color.h>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>

#include "search.hpp"
#include "clear.hpp"


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
        }
        if (key == -1) {
            fmt::print(
                fg(fmt::color::crimson) | fmt::emphasis::bold,
                "> Your previous choice was invalid.\n"
            );
            fmt::print(
                fg(fmt::color::crimson) | fmt::emphasis::bold,
                "> The option you selected is not a valid positive number. Try again! 👍\n"
            );
            return ROUTE::CONTINUE;
        }
        if (key == 1) {
            return ROUTE::EXIT_PROGRAM;
        }
        if (key == 2) {
            return ROUTE::SEARCH_TEXT_FILE;
        }
        return ROUTE::CONTINUE;
    }

    static std::vector<std::vector<std::string>> readFile(
        const std::string& file
    ) {
        std::ifstream ifFile;
        ifFile.open(file);
        std::vector<std::string> fBuffer{};
        std::vector<std::vector<std::string>> tokens{};
        if (ifFile.is_open()) {
            std::string line;
            while (std::getline(ifFile, line, '\n')) {
                fBuffer.push_back(line);
            }
            ifFile.close();
            for (const auto& fileRow : fBuffer) {
                std::stringstream ss(fileRow);
                std::vector<std::string> row;
                std::string word;
                while (ss >> word) {
                    row.push_back(word);
                }
                tokens.push_back(row);
            }
        }
        else {
            fmt::print(
                fg(fmt::color::crimson) | fmt::emphasis::bold,
                "> The file selected could not be opened. Make sure to provide a valid file path. Try again! 👍\n"
            );
        }
        return tokens;
    }

    static std::string strConvertToLower(const std::string& str) {
        std::string tmp{};
        for (const char& ch : str) {
            tmp += std::tolower(ch);
        }
        return tmp;
    }

    static std::map<std::pair<std::uint64_t, std::uint16_t>, std::vector<std::string>> match(
        const std::vector<std::vector<std::string>>& tokenData,
        const std::string& matchCriteria) {
        std::map<std::pair<std::uint64_t, std::uint16_t>, std::vector<std::string>> matchResult;
        for (size_t rowIndex = 0; rowIndex < tokenData.size(); rowIndex++) {
            for (size_t wordIndex = 0; wordIndex < tokenData.at(rowIndex).size(); wordIndex++) {
                if (strConvertToLower(tokenData.at(rowIndex).at(wordIndex)) ==
                    strConvertToLower(matchCriteria)) {
                    std::uint64_t tempValidRow, tempValidColumn;
                    tempValidRow = rowIndex + 1;
                    tempValidColumn = wordIndex + 1;
                    matchResult[std::pair(tempValidRow, tempValidColumn)].push_back(
                        tokenData.at(rowIndex).at(wordIndex));
                }
            }
        }
        return matchResult;
    }

    void executeSearch(const std::string& filePath, const std::string& matchCriteria) {
        const auto tokenData = readFile(filePath);
        auto matchResult = match(tokenData, matchCriteria);
        if (!matchResult.empty()) {
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "\n> Results Below: \n\n"
            );
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "\n> File: {}\n\n",
                filePath
            );
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "========================\n"
            );
            for (const auto& [key, value] : matchResult) {
                for (const auto& strMatch : value) {
                    fmt::print(
                        fg(fmt::color::green) | fmt::emphasis::bold,
                        "Match on row {} word number {} : {} \n",
                        key.first,
                        key.second,
                        strMatch
                    );
                }
            }
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "========================\n"
            );
        } else {
            fmt::print(
               fg(fmt::color::green) | fmt::emphasis::bold,
               "\n> No matches! \n\n"
           );
        }
    }

    void searchFile() {
        clearTerminal();
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "> File Path: "
        );
        std::string filePath, matchCriteria;
        std::cin >> filePath;
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "\n> Search Text: "
        );
        std::cin >> matchCriteria;
        executeSearch(filePath, matchCriteria);
    }

    void searchFile(const std::string& filePath, const std::string& matchCriteria) {
        executeSearch(filePath, matchCriteria);
    }

    void argCommands(const char* argv[], const int& argc) {
        if (argc == 4 && strcmp(argv[1], "--search-ts") == 0 && strlen(argv[3]) > 0) {
            const std::string filePath = argv[2];
            const std::string matchCriteria = argv[3];
            searchFile(filePath, matchCriteria);
            fmt::print("Hit any key to exit:");
            std::cin.get();
        }
        else {
            fmt::print("Please use one of the following commands:\n");
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "--search-ts\n\t > Search text file. takes two arguments the path of the file and the text you wish to match. "
            );
        }
    }
}
