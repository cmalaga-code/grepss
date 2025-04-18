#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "read.h"

std::string readTextFile(const std::string& f) {
    std::ifstream file(f);
    if (!file) {
        return "";
    }
    std::vector<std::string> data {};
    std::string lineBuffer {};

    while (std::getline(file, lineBuffer)) {
        std::cout << lineBuffer << std::endl;
    }
    return "";
}
