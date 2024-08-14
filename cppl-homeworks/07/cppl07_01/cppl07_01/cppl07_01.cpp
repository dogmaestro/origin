#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string text{ "Hello world!!" };
    std::cout << "[IN]: " << text << std::endl;

    std::map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }

    std::vector<std::pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

    std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return b.second < a.second; 
        });

    std::cout << "[OUT]:" << std::endl;

    for (const auto& pair : freqVec) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
