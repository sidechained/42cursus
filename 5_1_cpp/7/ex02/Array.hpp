#include <iostream>

template <typename T>
class MyContainer {
private:
    T element;

public:
    MyContainer(const T& value) : element(value) {}

    void print() {
        std::cout << element << std::endl;
    }
};