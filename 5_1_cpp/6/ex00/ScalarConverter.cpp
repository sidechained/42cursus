#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

int ScalarConverter::isStringChar(std::string s, char& result)
{
	if (s.length() != 1)
		return false;
	if (s[0] < 0 || s[0] > 127)
		return false;
	result = s[0];
	return true;
}

int ScalarConverter::isStringInt(std::string s, int& result)
{
	for (size_t i = 0; i < s.length(); ++i) {
		if (!isdigit(s[i]) && (i == 0 && s[i] != '-' && s[i] != '+'))
			return false;
	}
	std::istringstream(s) >> result;
	return true;
}

int ScalarConverter::isStringFloat(std::string s, float& result)
{
	std::istringstream iss(s);

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return 2;
	iss >> result;
	return !iss.fail() && iss.eof();
}

int ScalarConverter::isStringDouble(std::string s, double& result)
{
	std::istringstream iss(s);

	if (s == "-inf" || s == "+inf" || s == "nan")
		return 2;
	iss >> result;
	return !iss.fail() && iss.eof();
}

void ScalarConverter::detectChar(std::string s)
{		
	char charValue;
	if (isStringChar(s, charValue))
	{
		std::cout << "Detected as char..." << std::endl;
		if (charValue < 32 || charValue > 126)
			std::cout << "char: unprintable" << std::endl;
		else
			std::cout << "char: " << charValue << std::endl;
		std::cout << "int: " << static_cast<int>(charValue) << std::endl;
        std::cout << "float: " << static_cast<float>(charValue) << std::endl;
        std::cout << "double: " << static_cast<double>(charValue) << std::endl;
	}
	else
		printImpossible();
}

void ScalarConverter::detectInt(std::string s)
{
	int intValue;
	if (isStringInt(s, intValue))
	{
		std::cout << "Detected as int..." << std::endl;
		if (static_cast<char>(intValue) < 32 || static_cast<char>(intValue) > 126)
			std::cout << "char: unprintable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(intValue) << std::endl;
		std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << static_cast<float>(intValue) << std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << std::endl;
	}
	else
		printImpossible();
}

void ScalarConverter::detectFloat(std::string s)
{
	float floatValue;
	switch (isStringFloat(s, floatValue))
	{
		case PSEUDOLITERAL:
			std::cout << "Detected as float..." << std::endl;
			std::cout << "char: impossible" << std::endl;		
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << s << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
		case true:
			std::cout << "Detected as float..." << std::endl;
			if (static_cast<char>(floatValue) < 32 || static_cast<char>(floatValue) > 126)
				std::cout << "char: unprintable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(floatValue) << std::endl;
			std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
			std::cout << "float: " << floatValue << std::endl;
			std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
			break;
		default:
			printImpossible();
	}
}

void ScalarConverter::detectDouble(std::string s)
{
	double doubleValue;
	switch (isStringDouble(s, doubleValue))
	{
		case PSEUDOLITERAL:
			std::cout << "Detected as double..." << std::endl;
			std::cout << "char: impossible" << std::endl;		
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << s << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
		case true:
			std::cout << "Detected as double..." << std::endl;
			if (static_cast<char>(doubleValue) < 32 || static_cast<char>(doubleValue) > 126)
				std::cout << "char: unprintable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(doubleValue) << std::endl;	
			std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
			std::cout << "float: " << static_cast<float>(doubleValue) << std::endl;
			std::cout << "double: " << doubleValue << std::endl;
			break;
		default:
			printImpossible();
	}
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;		
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string s)
{
	bool pseudoFloatFlag = false;
	if (s == "-inff" || s == "+inff" || s == "nanf")
		pseudoFloatFlag = true;
	bool pseudoDoubleFlag = false;
	if (s == "-inf" || s == "+inf" || s == "nan")
		pseudoDoubleFlag = true;	
	bool intFlag = true;
	for(unsigned int i = 0; i < s.length(); i++)
		if (!(isdigit(s[i])))
			intFlag = false;
	bool pointFlag = false;
	for(unsigned int i = 0; i < s.length(); i++)
		if (s[i] == '.')
			pointFlag = true;
	if (intFlag)
		detectInt(s);
	else if (s.length() == 1 && s[0] >= 0 && s[0] <= 127)
		detectChar(s);
	else if (pointFlag || pseudoFloatFlag || pseudoDoubleFlag)
	{
		if (pseudoFloatFlag)
		{
			detectFloat(s);
		}
		else if (pseudoDoubleFlag)
		{
			detectDouble(s);
		}
		else if (s[s.length() - 1] == 'f')
		{
			s.resize(s.size() - 1);
			detectFloat(s);
		}
		else 
		{
			
			detectDouble(s);
		}
	}
	else
	{
		printImpossible();
	}
}