#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T element)
{
	std::cout << element << " ";
}

void printIntElement(int element)
{
	std::cout << element << " ";
}

void printPerson(Person person)
{
	std::cout << "	Person name: " << person.name << std::endl;
	std::cout << "	Person age: " << person.age << std::endl;
}

int main()
{
	std::cout << "1. Testing with integer array and non-template function..." << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intArraySize, printIntElement);
	std::cout << std::endl << std::endl;

	std::cout << "2. Testing with double array and template function..." << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	iter(doubleArray, doubleArraySize, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "3. Testing with string array and template function..." << std::endl;
	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);
	iter(stringArray, stringArraySize, printElement);
	std::cout << std::endl << std::endl;

	std::cout << "4. Testing with complex type (Person struct)..." << std::endl;
	Person personArray[2];
	personArray[0].name = "Bob";
	personArray[0].age = 32;
	personArray[1].name = "Jill";
	personArray[1].age = 8;	
	size_t personArraySize = sizeof(personArray) / sizeof(personArray[0]);
	iter(personArray, personArraySize, printPerson);

	return 0;
}