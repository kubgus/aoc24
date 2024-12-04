#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

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

inline int num_at(uint32_t& i, std::string& input) {
    std::string buf;
    for (
        int n = 1;
        n <= 3 && i+n < input.size() && std::isdigit(input[i+n]);
        n++
    ) {
        buf += input[i+n];
    }
    i += buf.size() + 1;
    return std::stoi(buf);
}

uint64_t solve(std::string& input) {
    uint64_t solution = 0;
    for (uint32_t i = 0; i < input.size(); i++) {
        if (i < 3 || input[i] != '(') continue;
        char& m = input[i-3];
        char& u = input[i-2];
        char& l = input[i-1];
        if (m != 'm' || u != 'u' || l != 'l') continue;
        int first = num_at(i, input);
        if (input[i] != ',') continue;
        int second = num_at(i, input);
        if (input[i] != ')') continue;
        solution += first * second;
    }
    return solution;
}

int main(int argc, char **argv) {
    std::string input = readfile(argv[1]);
    uint64_t solution = solve(input);
    std::cout << solution << std::endl;
}
