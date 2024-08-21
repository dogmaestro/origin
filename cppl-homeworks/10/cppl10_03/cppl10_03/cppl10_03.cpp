#include <iostream>

template <class T>
class UniquePtr {
public:
	UniquePtr<T>(T* ptr) : ptr_(ptr) {}
	UniquePtr<T>& operator=(const UniquePtr&) = delete;
	UniquePtr<T>(const UniquePtr&) = delete;

	~UniquePtr<T>() {
		delete ptr_;
	}

	T* release() {
		T* tmp = ptr_;
		ptr_ = nullptr;
		return tmp;
	}

	T& operator*() const {
		return *ptr_;
	}

private:
	T* ptr_ = nullptr;
};


int main() {

	UniquePtr<int> ptr1(new int(1));
	UniquePtr<int> ptr2(new int(2));

	std::cout << "*ptr1\t  " << *ptr1 << std::endl;
	std::cout << "*ptr2\t  " << *ptr2 << std::endl;
};