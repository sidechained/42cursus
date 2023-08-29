#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <cstdlib>
#include <string>

#define PSEUDOLITERAL 2

class ScalarConverter
{
	private:
		static int isStringChar(std::string s, char& result);
		static int isStringInt(std::string s, int& result);
		static int isStringFloat(std::string s, float& result);
		static int isStringDouble(std::string s, double& result);
		static void detectChar(std::string s);
		static void detectInt(std::string s);
		static void detectFloat(std::string s);
		static void detectDouble(std::string s);
		static void printImpossible();
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		~ScalarConverter();		
	public:
		static void convert(std::string s);
};

#endif
