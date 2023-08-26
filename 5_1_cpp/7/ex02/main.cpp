#include "Array.hpp"
#include <iostream>
#define SIZE 5

int main()
{
	std::cout << "Create an empty array and print the size using the public size() method:" << std::endl;
	Array<int> defaultArray;
	std::cout << defaultArray.size() << std::endl;

	std::cout << "Create an array of size n (by passing n in constructor) and print the size using the public size() method:" << std::endl;
	Array<float> sizedArray1(SIZE);
	std::cout << sizedArray1.size() << std::endl;

	std::cout << "Set and print the contents of the array:" << std::endl;
	for (unsigned int i = 0; i < SIZE; i++)
		sizedArray1[i] = i + 1;	
	std::cout << sizedArray1 << std::endl;

	std::cout << "Initialise, set contents and print a new array of the same type (float) but different size:" << std::endl;
	Array<float> sizedArray2(SIZE - 2);
	for (unsigned int i = 0; i < SIZE - 2; i++)
		sizedArray2[i] = i + 1;	
	std::cout << sizedArray2 << std::endl;

	std::cout << "Copy original array using '=' operator Print the contents (resizes):" << std::endl;
	sizedArray2 = sizedArray1;
	std::cout << sizedArray2 << std::endl;

	std::cout << "Modify first element of original array, last element of the new copy, then print both (they should differ):" << std::endl;
	sizedArray1[0] = 10;
	sizedArray2[SIZE - 1] = 20;	
	std::cout << sizedArray1 << std::endl;
	std::cout << sizedArray2 << std::endl;

	std::cout << "Copy and print the original array using copy constructor (should be same as original):" << std::endl;
	Array<float> sizedArray3(sizedArray1);
	std::cout << sizedArray3 << std::endl;

	std::cout << "Modify first element of original array, last element of the new copy, then print both (they should differ):" << std::endl;
	sizedArray1[0] = 30;
	sizedArray3[SIZE - 1] = 40;	
	std::cout << sizedArray1 << std::endl;
	std::cout << sizedArray3 << std::endl;

	std::cout << "Access elements using []..." << std::endl;
	try
	{
		std::cout << "-Trying to access a valid index..." << std::endl << sizedArray3[1] << std::endl;
		std::cout << "-Trying to access an invalid index..." << std::endl << sizedArray3[SIZE] << std::endl;
	}
	catch ( Array<float>::OutOfBoundsException& e ) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}