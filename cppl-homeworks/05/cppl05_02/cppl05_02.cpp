#include <iostream>

template <typename T>
class table {
private:
    int rows, cols;
    T** array;

public:
    table(int rows, int cols) : rows(rows), cols(cols) {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new T[cols];
        }
    }

    ~table() {
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    T* operator[](int row) {
        return array[row];
    }

    const T* operator[](int row) const {
        return array[row];
    }

    int Size() const {
        return cols * rows;
    }
};

int main() {

    auto test = table<int>(2, 3);

    test[0][0] = 4;

    std::cout << test[0][0] << std::endl;

    return 0;
}
