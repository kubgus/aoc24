#include <algorithm>
#include <array>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::array<std::vector<int>, 2> get_arrays(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "could not open file " << filename << std::endl;
        return { {} };
    }

    std::vector<int> first, second;
    bool diff = true;
    std::string buffer;
    while (std::getline(file, buffer)) {
        for (int i = 0; i < buffer.size(); i++) {
            if (!std::isdigit(buffer[i])) continue;
            std::string digit_buffer;
            for (;std::isdigit(buffer[i]); i++) {
                digit_buffer += buffer[i];
            }
            int num = std::stoi(digit_buffer);
            if (diff) first.push_back(num);
            else second.push_back(num);
            diff = !diff;
        }
    }

    file.close();
    return { first, second };
}

int main(int argc, char **argv) {
    auto arrays = get_arrays(argv[1]);
    auto& first = arrays[0];
    std::sort(first.begin(), first.end());
    auto& second = arrays[1];
    std::sort(second.begin(), second.end());
    int result = 0;
    for (int i = 0; i < first.size(); i++) {
        result += std::abs(first[i] - second[i]);
    }
    std::cout << result << std::endl;
}
