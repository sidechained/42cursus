#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T element)
{
    std::cout << element << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    iter(intArray, intArrayLength, printElement);

    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    iter(doubleArray, doubleArrayLength, printElement);

    return 0;
}