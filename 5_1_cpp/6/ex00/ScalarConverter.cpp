#include "ScalarConverter.hpp"

// TODO: could handle numeric limits

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &obj)
{
	this->s = obj.s;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	
}

// CRITERIA:
// string length must = 1, and first (only) char must be printable (i.e. ascii 32-127)
bool ScalarConverter::isChar(std::string s)
{
	if (s.length() != 1)
		return(false);
	else if (s[0] >= 32 && s[0] <= 127)
		return (true);
	else
	{
		std::cout << "WARNING: char not printable" << std::endl;
		return(false);
	}
}

// CRITERIA:
// 1. if first char is + or -, disregard it and continue
// 2. all other chars must be digits
// 3. must be at least one digit
// 4. must be within INT_MIN/MAX limits
bool ScalarConverter::isInt(std::string s)
{
	unsigned long i = 0;
	
	// 1.
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	// 2.
	int digitCount = 0;
	while(i < s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return(false);
		digitCount++;
		i++;
	}
	// 3.
	if (digitCount <= 0)
		return(false);
	// 4. INT_MIN/MAX range check
	if (std::atof(s.c_str()) > static_cast<double>(INT_MAX) || std::atof(s.c_str()) < static_cast<double>(INT_MIN))
		return(false);
	return(true);
}

// CRITERIA:
// 1. string length should not be less than 3 chars i.e. minimum of e.g. '0.0'
// 2. if first char is + or -, disregard it and continue
// 3. first char (after +-) and last char must be digits
// 4. second char up to last-but-one char must be digits or decimal point
// 5. if more than one decimal point counted, return false
bool ScalarConverter::isDouble_BaseRules(std::string s)
{
	unsigned long i = 0;

	// 1.
	if (s.length() < 3)
		return(false);
	// 2.
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	// 3.
	if (s[i] < '0' || s[i] > '9')
		return(false);
	if (s[s.length()-1] < '0' || s[s.length()-1] > '9')
		return(false);
	// 4.
	int decimalPointCount = 0;
	while(i < s.length())
	{
		if (s[i] == '.')
			decimalPointCount++;
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
			return(false);
		i++;
	}
	// 5.
	if (decimalPointCount != 1)
		return(false);
	return(true);
}

// CRITERIA:
// 0. if string is "-inff" or "+inff" or "nanf", string is considered to be a float
// 1. if last char is not 'f', string is considered not to be a double 
// 2. strip off the 'f', then apply all other rules as for double
bool ScalarConverter::isFloat(std::string s)
{
	// 0.
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return(true);
	// 1.
	if (s[s.length()-1] != 'f')
		return(false);
	// 2.
	s.resize(s.size()-1);
	return(isDouble_BaseRules(s));
}

// CRITERIA:
// 0. if string is "-inf" or "+inf" or "nan", string is considered to be a double
// 1. if not, apply base rules
bool ScalarConverter::isDouble(std::string s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return(true);
	return(isDouble_BaseRules(s));
}

int ScalarConverter::convertToInt(std::string s)
{
	std::istringstream intStream(s);
	int intValue;

	if (intStream >> intValue)
		return intValue;
	else
		return 0;
}

float ScalarConverter::convertToFloat(std::string s)
{
	std::istringstream floatStream(s);
	float floatValue;

	if (floatStream >> floatValue)
		return floatValue;
	else
		return 0.0;
}

double ScalarConverter::convertToDouble(std::string s)
{
	std::istringstream doubleStream(s);
	double doubleValue;
	if (doubleStream >> doubleValue)
		return doubleValue;
	else
		return 0.0;
}

void ScalarConverter::convert(std::string s)
{
	std::cout << "String = \"" << s << "\"" << std::endl;
	if(isChar(s))
		std::cout << "char: " << s << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if(isInt(s))
	{
		std::cout << "int: " << convertToInt(s) << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	if(isFloat(s))
	{
		if (s == "-inff" || s == "+inff" || s == "nanf")
			std::cout << "float: " << s << std::endl;
		else
			std::cout << "float: " << convertToFloat(s) << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;

	if(isDouble(s))
		if (s == "-inf" || s == "+inf" || s == "nan")
			std::cout << "double: " << s << std::endl;	
		else
			std::cout << "double: " << convertToDouble(s) << std::endl;		
	else
		std::cout << "double: impossible" << std::endl;
	std::cout << std::endl;			
}
