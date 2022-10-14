#include <stdlib.h>
#include <iostream>

// https://isocpp.org/wiki/faq/serialization#serialize-text-format

// std::string gen_random(const int len) {
//     static const char alphanum[] =
//         "0123456789"
//         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//         "abcdefghijklmnopqrstuvwxyz";
//     std::string tmp_s;
//     tmp_s.reserve(len);

//     for (int i = 0; i < len; ++i) {
//         tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
//     }
    
//     return tmp_s;
// }

struct Data {
  std::string* ptrToRandStr1;
  int randInt;
  std::string* ptrToRandStr2; 
} myData;

// Q: this function is supposed to return an address, but how can it when the type is void?
void* serialize(void)
{
	std::string* ptrToRandStr1;
 	int randInt;
  	std::string* ptrToRandStr2;
    char* raw;

    raw = new char[20];

  	*ptrToRandStr1 = "abcde";
  	randInt = rand() % 100;
  	*ptrToRandStr2 = "fghij";

    // return the address on the heap of a sequence of bytes that represent a piece of serialized data

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(void * raw)
{
	// deserialize the raw data to a data structure
	// that contains the same elements that you just serialized and allocated on the heap
    myData.ptrToRandStr1 = ;
    myData.randInt = ;
    myData.ptrToRandStr2 = ;
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	serialize();
	deserialize
}
