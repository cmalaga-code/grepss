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
        }
        else {
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "\n> No matches! \n\n"
            );
        }
    }

    void executeSearch(const std::string& filePath, const std::string& matchCriteria, const std::string& output) {
        const auto tokenData = readFile(filePath);
        auto matchResult = match(tokenData, matchCriteria);
        std::ofstream ofFile(output);
        if (ofFile.is_open()) {
            ofFile << "========================\n";
            for (const auto& [key, value] : matchResult) {
                for (const auto& strMatch : value) {
                    ofFile <<
                        fmt::format("Match on row {} word number {} : {} \n",
                                    key.first,
                                    key.second,
                                    strMatch
                        );
                }
            }
            ofFile << "========================\n";
            ofFile.close();
            fmt::print("\n\t > Successfully created file ✅\n\n");
        }
        else {
            fmt::print("\n\t > Failed to create file ❌\n\n");
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

    void searchFile(const std::string& filePath, const std::string& matchCriteria, const std::string& output) {
        executeSearch(filePath, matchCriteria, output);
    }

    void help() {
        fmt::print("\n============================================\n\n");
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "1) grepster.exe --search-ts C:\\Users\\username\\Downloads\\filetosearch.txt \"test\"\n\n"
        );
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "\t > Search text file for search text and output on the shell"
            "\n\t\t > --search-ts stands for search text file"
            "\n\t\t\t > takes 2 arguments the path to file and the search text\n\n"
        );
        fmt::print(
           fg(fmt::color::green) | fmt::emphasis::bold,
           "2) grepster.exe --search-ts C:\\Users\\username\\Downloads\\filetosearch.txt \"test\" -o C:\\Users\\username\\output.txt\n\n"
       );
        fmt::print(
            fg(fmt::color::green) | fmt::emphasis::bold,
            "\t > Search text file for search text and output to a file"
            "\n\t\t > --search-ts stands for search text file"
            "\n\t\t\t > takes 2 arguments the path to file and the search text"
            "\n\t\t > -o stands for output and outputs a text file with the match information"
            "\n\t\t\t > -o is optional"
            "\n\t\t\t > -o takes in one argument the output path\n\n"
        );
        fmt::print("Hit enter key to exit:\n");
        fmt::print("\n============================================\n");
        std::cin.get();
    }

    void argCommands(const char* argv[], const int& argc) {
        if (argc == 2 && strcmp(argv[1], "--help") == 0) {
            help();
        }
        else if (argc == 4 && strcmp(argv[1], "--search-ts") == 0 && strlen(argv[2]) > 0 && strlen(argv[3]) > 0) {
            const std::string filePath = argv[2];
            const std::string matchCriteria = argv[3];
            searchFile(filePath, matchCriteria);
            fmt::print("Hit enter key to exit:");
            std::cin.get();
        }
        else if (argc == 6 && strcmp(argv[1], "--search-ts") == 0 && strlen(argv[2]) > 0 && strlen(argv[3]) > 0 &&
            strcmp(argv[4], "-o") == 0 &&
            strlen(argv[5]) > 0) {
            const std::string filePath = argv[2];
            const std::string matchCriteria = argv[3];
            const std::string output = argv[5];
            searchFile(filePath, matchCriteria, output);
        }
        else {
            fmt::print(
                fg(fmt::color::green) | fmt::emphasis::bold,
                "\n\n> Use the command --help\n\n"
            );
        }
    }
}
