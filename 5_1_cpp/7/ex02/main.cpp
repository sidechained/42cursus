#include "Array.hpp"

int main() {
    MyContainer<int> container1(42);
    container1.print();  // Output: 42

    MyContainer<std::string> container2("Hello, World!");
    container2.print();  // Output: Hello, World!

    return 0;
}