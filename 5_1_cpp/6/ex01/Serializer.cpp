#include "Serializer.hpp"

// Write a program to test that your class works as expected.
// You must create a non-empty (it means it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
// Do not forget to turn in the files of your Data structure.

Data Serializer::data;

void Serializer::initializeData()
{
    time_t t;
    srand((unsigned) time(&t));
    data.str1 = generateRandomString();
    data.i = rand();
    data.str2 = generateRandomString();
}

std::string Serializer::generateRandomString()
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int strlen = (rand() % 7) + 3;
	std::string randomString;
	
	randomString.resize(strlen);
	for(int i = 0; i < strlen; i++)
		randomString[i] = alphabet[rand() % 26];
	return randomString;
}

void Serializer::printData(Data* data)
{
	std::cout << "first random string (before deserialization): " << data->str1 << std::endl;
	std::cout << "integer (before deserialization): " << data->i << std::endl;
	std::cout << "second random string  (before deserialization): " << data->str2 << std::endl;
    std::cout << std::endl;
}

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* dataToSerialize)
{
	Serializer::printData(dataToSerialize);
    return reinterpret_cast<uintptr_t>(dataToSerialize);
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw)
{
    Data* deserialisedData;
    deserialisedData = reinterpret_cast<Data*>(raw);
	Serializer::printData(deserialisedData);
    return deserialisedData;
}

Data* Serializer::getData()
{
    return &data;
}