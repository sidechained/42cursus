#include <iostream>
#include <time.h>	
#include "main.hpp"

std::string generateRandomString()
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int strlen = rand() % 10;
	std::string randomString;
	int i = 0;
	time_t t;

	randomString.resize(strlen);
	srand((unsigned) time(&t));

	while(i < strlen)
	{
		randomString[i] = alphabet[rand() % 26];
		i++;
	}
	return(randomString);
}

void*	serialize(Data *ptrToData_before)
{
	return reinterpret_cast<void*>(ptrToData_before);
}

Data*	deserialize(void* ptrToData_serialized)
{
	return reinterpret_cast<Data*>(ptrToData_serialized);
}

int	main()
{
	Data*		ptrToData_before = new Data;
	Data*		ptrToData_after;
	void*		ptrToData_serialized;

	ptrToData_before->str1 = generateRandomString();
	ptrToData_before->i = rand();
	ptrToData_before->str2 = generateRandomString();
	ptrToData_serialized = serialize(ptrToData_before);
	ptrToData_after = deserialize(ptrToData_serialized);

	std::cout << std::endl;	
	std::cout << "first random string (before deserialization): " << ptrToData_before->str1 << std::endl;
	std::cout << "integer (before deserialization): " << ptrToData_before->i << std::endl;
	std::cout << "second random string  (before deserialization): " << ptrToData_before->str2 << std::endl;
	std::cout << std::endl;
	std::cout << "first random string (after deserialization): " << ptrToData_after->str1 << std::endl;
	std::cout << "integer (after deserialization): " << ptrToData_after->i << std::endl;
	std::cout << "second random string  (after deserialization): " << ptrToData_after->str2 << std::endl;
	std::cout << std::endl;

	return(0);
}