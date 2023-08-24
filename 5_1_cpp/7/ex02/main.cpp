#include "Array.hpp"

#include <iostream>

#define SIZE 5

int main()
{
	std::cout << "Create an empty array using default constructor:" << std::endl;
	Array<int> defaultArray;

	std::cout << "Print the size using the public size() method:" << std::endl;
	std::cout << defaultArray.size() << std::endl;

	std::cout << "Create an array of size n by passing n in constructor:" << std::endl;
	Array<float> sizedArray1(SIZE);

	std::cout << "Print the size using the public size() method:" << std::endl;
	std::cout << sizedArray1.size() << std::endl;

	std::cout << "Set and print the contents of the array:" << std::endl;
	for (unsigned int i = 0; i < SIZE; i++)
		sizedArray1[i] = i + 1;	
	std::cout << sizedArray1 << std::endl;

	std::cout << "Initialise a new array of the same type (float) but different size:" << std::endl;
	Array<float> sizedArray2(SIZE - 2);

	std::cout << "Copy original array using = operator:" << std::endl;
	std::cout << " (resizes to size of array to be copied by deleting and creating a new one)" << std::endl;	
	sizedArray2 = sizedArray1;

	std::cout << "Print the contents of the copied array (should be same as original):" << std::endl;
	std::cout << sizedArray2 << std::endl;

	std::cout << "Modify first element of original array, last element of the new copy, then print both (they should differ):" << std::endl;
	sizedArray1[0] = 10;
	sizedArray2[SIZE - 1] = 20;	
	std::cout << sizedArray1 << std::endl;
	std::cout << sizedArray2 << std::endl;

	std::cout << "Copy original array using copy constructor:" << std::endl;
	Array<float> sizedArray3(sizedArray1);

	std::cout << "Print the contents of the copied array (should be same as original):" << std::endl;
	std::cout << sizedArray3 << std::endl;

	std::cout << "Modify first element of original array, last element of the new copy, then print both (they should differ):" << std::endl;
	sizedArray1[0] = 30;
	sizedArray3[SIZE - 1] = 40;	
	std::cout << sizedArray1 << std::endl;
	std::cout << sizedArray3 << std::endl;

	std::cout << "Access elements using []..." << std::endl;
	try
	{
		std::cout << "	Trying to access a valid index..." << std::endl << "\t\t" << sizedArray3[1] << std::endl;
		std::cout << "	Trying to access an invalid index..." << std::endl << "\t\t" << sizedArray3[SIZE] << std::endl;
	}
	catch ( Array<float>::OutOfBoundsException& e ) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}