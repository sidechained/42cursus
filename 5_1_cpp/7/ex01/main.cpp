#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T element)
{
	std::cout << element << " ";
}

int main()
{
	std::cout << "1. Testing with integer array..." << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intArraySize, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "2. Testing with double array..." << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	iter(doubleArray, doubleArraySize, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "3. Testing with string array..." << std::endl;
	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);
	iter(stringArray, stringArraySize, printElement);
	std::cout << std::endl << std::endl;

	return 0;
}