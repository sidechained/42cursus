#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdint.h>

struct Data
{
	std::string str1;
	int			i;
	std::string str2;
};

class Serializer
{
	private:
		static Data data;
		Serializer();
		Serializer(Serializer &obj);
		Serializer &operator=(Serializer &obj);
		~Serializer();
		static std::string generateRandomString();
		static void printData(Data* data);
	public:
		static void initializeData();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		static Data* getData();
};

#endif