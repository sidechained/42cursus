#include <iostream>

// TODO: could handle numeric limits

// CRITERIA:
// string length must = 1, and first (only) char must be printable (i.e. ascii 32-127)
bool isChar(std::string s)
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
bool isInt(std::string s)
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
	if (digitCount > 0)
		return(true);
	else
		return(false);
}

// CRITERIA:
// 1. string length should not be less than 3 chars i.e. minimum of e.g. '0.0'
// 2. if first char is + or -, disregard it and continue
// 3. first char (after +-) and last char must be digits
// 4. second char up to last-but-one char must be digits or decimal point
// 5. if more than one decimal point counted, return false
bool	isDouble_BaseRules(std::string s)
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
bool	isFloat(std::string s)
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
bool	isDouble(std::string s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return(true);
	return(isDouble_BaseRules(s));
}

void	convert(std::string s)
{
		std::cout << "String = \"" << s << "\"" << std::endl;
		if(isChar(s))
			std::cout << "char: " << s << std::endl;
		else
			std::cout << "char: impossible" << std::endl;

		if(isInt(s))
			std::cout << "int: " << stoi(s) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		if(isFloat(s))
			std::cout << "float: " << stof(s) << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;

		if(isDouble(s))
			std::cout << "double: " << stod(s) << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
		std::cout << std::endl;			
}


int main()
{
	std::cout << std::endl;		
	std::cout << "- Testing one example of each type" << std::endl;	
	convert("a");
	convert("42");
	convert("4.2f");	
	convert("4.2");

	std::cout << "- Testing various edge cases" << std::endl;	
	std::cout << "[This should match both char and int]" << std::endl;	
	convert("4");
	std::cout << "[This shouldn't be considered a double (only 0.2 should)]" << std::endl;	
	convert(".2");
	std::cout << "[This shouldn't be considered a float (only 1.0f should)]" << std::endl;		
	convert("1.f");
	std::cout << "[This should be considered a double]" << std::endl;			
	convert("-12.0");
	std::cout << "[This should be considered a char but not a double]" << std::endl;				
	convert("-");
	std::cout << "[This shouldn't be considered a double]" << std::endl;					
	convert("--");	
	std::cout << "[Multiple decimal points should not be accepted]" << std::endl;						
	convert("12..0");
	std::cout << "[Decimal point following +/- should not be accepted]" << std::endl;						
	convert("+.12");			
	std::cout << "[This should only be considered an int]" << std::endl;						
	convert("120");
	std::cout << "[This should be identified as special case of float]" << std::endl;							
	convert("-inff");
	std::cout << "[This should be identified as special case of double]" << std::endl;							
	convert("nan");
	std::cout << "[Empty string should not pass for any type]" << std::endl;	
	convert("");
}