#include <iostream>
#include <algorithm>

class DivisibleByThree {
public:
    DivisibleByThree() : sum(0), count(0) {}

    void operator()(int number) {
        if (number % 3 == 0) {
            sum += number;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }

private:
    int sum;
    int count;
};

int main() {
    int numbers[] = {4, 1, 3, 6, 25, 54};

    std::cout << "[IN]: ";
    for (const auto& elem : numbers) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    DivisibleByThree functor;

    functor = std::for_each(numbers, numbers + (sizeof(numbers) / sizeof(numbers[0])), functor);

    std::cout << "[OUT]: get_sum = " << functor.get_sum() << std::endl;

    std::cout << "[OUT]: get_count = " << functor.get_count() << std::endl;

    return 0;
}
