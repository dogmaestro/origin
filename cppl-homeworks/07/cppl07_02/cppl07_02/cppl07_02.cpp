#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {

    std::set<int> uniqueNumbers;
    std::vector<int> numbers;
    int size, number;

    std::cout << "[IN]:" << std::endl;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cin >> number;
        numbers.push_back(number);
    }

    for (int num : numbers) {
        uniqueNumbers.insert(num);
    }

    std::vector<int> sortedNumbers(uniqueNumbers.begin(), uniqueNumbers.end());

    std::sort(sortedNumbers.begin(), sortedNumbers.end(), std::greater<int>());

    std::cout << "[OUT]:" << std::endl;
    for (int num : sortedNumbers) {
        std::cout << num << std::endl;
    }
  
    return 0;
}
