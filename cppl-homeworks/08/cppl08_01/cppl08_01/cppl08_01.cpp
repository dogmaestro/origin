#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void removeDuplicates(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());

    auto last = std::unique(vec.begin(), vec.end());

    vec.erase(last, vec.end());
}

int main() {
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: ";
    for (const auto& v : vec) {
        std::cout << v << " ";
    }

    std::cout << std::endl;

    removeDuplicates(vec);

    std::cout << "[OUT]: ";
    for (const auto& v : vec) {
        std::cout << v << " ";
    }

    return 0;
}
