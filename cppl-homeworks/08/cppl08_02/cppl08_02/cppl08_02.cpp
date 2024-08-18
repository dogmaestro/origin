#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <list>

template <typename T>
void print_container(const T& test_container) {
    for (auto it = test_container.begin(); it != test_container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);

    return 0;
}
