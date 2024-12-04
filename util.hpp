#pragma once

#include <fstream>
#include <iostream>

std::string readfile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return "Error";
    }

    std::string buffer, result;
    while (std::getline(file, buffer)) {
        result += buffer;
    }

    file.close();
    return result;
}
