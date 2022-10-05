#include <iostream>

bool isInteger(char c)
{
	if (c >= '0' && c <= '9')
		return(true);
	else
		return(false);
}

bool isPlusOrMinus(char c)
{
	if (c == '+' || c <= '-')
		return(true);
	else
		return(false);
}

bool isDecimalPoint(char c)
{
	if (c == '.')
		return(true);
	else
		return(false);
}

bool firstCharIsInteger(std::string s)
{
	if (isInteger(s[0]))
		return(true);
	else
		return (false);
}

bool firstCharIsPlusOrMinus(std::string s)
{
	if (isPlusOrMinus(s[0]))
		return(true);
	else
		return (false);
}

bool allButFirstCharAreIntegers(std::string s)
{
	int i = 1;
	while(s[i] != '\0')
	{
		if (!isInteger(s[i]))
			return(false);
		i++;
	}
	return(true);
}

// or decimal point
bool allButFirstAndLastCharsAreIntegersOrDecimalPoint(std::string s)
{
	int l;
	int i;

	l = 0;
	while(s[l] != '\0')
		l++;

	if (l < 3)
		return(true);

	i = 1;
	while(i != (l-1))
	{	
		if (!
			(isInteger(s[i]) || isDecimalPoint(s[i]))
			)
			return(false);
		i++;
	}
	return(true);
}

// should be contains SINGLE decimal point
bool containsDecimalPoint(std::string s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '.')
			return(true);
		i++;
	}
	return(false);	
}

bool lastCharIsF(std::string s)
{
	int l;
	l = 0;
	while(s[l] != '\0')
		l++;
	if (s[l-1] == 'f')
		return(true);
	else
		return(false);
}

bool isChar(std::string s)
{
	if (s.length() == 1)
		return (true);
	else
		return(false);
}

bool isInt(std::string s)
{
	if ((firstCharIsPlusOrMinus(s) || firstCharIsInteger(s)) && (allButFirstCharAreIntegers(s)))
		return(true);
	else
		return(false);
}

// STUCK HERE: a plus may or not be present, 'allButFirstAndLastCharsAreIntegersOrDecimalPoint' is wrong assumption
bool isFloat(std::string s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return(true);

	if (
		containsDecimalPoint(s) && 
		(firstCharIsPlusOrMinus(s) || firstCharIsInteger(s)) &&
		lastCharIsF(s) &&
		allButFirstAndLastCharsAreIntegersOrDecimalPoint(s)
	)
		return(true);
	else
		return(false);
}

bool isDouble(std::string s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return(true);

	if (
		containsDecimalPoint(s) && 
		(firstCharIsPlusOrMinus(s) || firstCharIsInteger(s)) &&
		allButFirstCharAreIntegers(s)
	)
		return(true);
	else
		return(false);
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::string s = argv[1];

		// ADD PRINTABLE CHAR
		// if(isChar(s))
		// 	std::cout << "char: " << s[0] << std::endl;
		// else
		// 	std::cout << "char: impossible" << std::endl;

		// if(isInt(s))
		// 	std::cout << "int: " << stoi(s) << std::endl;
		// else
		// 	std::cout << "int: impossible" << std::endl;

		if(isFloat(s))
			std::cout << "float: " << stof(s) << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;

		// if(isDouble(s))
		// 	std::cout << "double: " << stod(s) << std::endl;
		// else
		// 	std::cout << "double: impossible" << std::endl;
	}
	else
		std::cout << "ERROR: Wrong number of arguments provided" << std::endl;	
}

