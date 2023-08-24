#include "ScalarConverter.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "- Testing one example of each type" << std::endl;	
	ScalarConverter::convert("a");
	ScalarConverter::convert("42");
	ScalarConverter::convert("4.2f");	
	ScalarConverter::convert("4.2");
	std::cout << "- Testing various edge cases" << std::endl;	
	std::cout << "[This should match both char and int]" << std::endl;
	ScalarConverter::convert("4");
	std::cout << "[This shouldn't be considered a double (only 0.2 should)]" << std::endl;	
	ScalarConverter::convert(".2");
	std::cout << "[This shouldn't be considered a float (only 1.0f should)]" << std::endl;		
	ScalarConverter::convert("1.f");
	std::cout << "[This should be considered a double]" << std::endl;			
	ScalarConverter::convert("-12.0");
	std::cout << "[This should be considered a char but not a double]" << std::endl;				
	ScalarConverter::convert("-");
	std::cout << "[This shouldn't be considered a double]" << std::endl;					
	ScalarConverter::convert("--");	
	std::cout << "[Multiple decimal points should not be accepted]" << std::endl;						
	ScalarConverter::convert("12..0");
	std::cout << "[Decimal point following +/- should not be accepted]" << std::endl;						
	ScalarConverter::convert("+.12");			
	std::cout << "[This should only be considered an int]" << std::endl;						
	ScalarConverter::convert("120");
	std::cout << "[This is below INT_MIN and so should not be considered an int]" << std::endl;						
	ScalarConverter::convert("-3493249324932493294");	
	std::cout << "[This is above INT_MAX and so should not be considered an int]" << std::endl;						
	ScalarConverter::convert("3493249324932493294");
	std::cout << "[This should be identified as special case of float]" << std::endl;							
	ScalarConverter::convert("-inff");
	std::cout << "[This should be identified as special case of double]" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "[Empty string should not pass for any type]" << std::endl;	
	ScalarConverter::convert("");
}