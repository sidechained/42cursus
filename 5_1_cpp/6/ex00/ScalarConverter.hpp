#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <climits>


// to make a class 'static' declare only static members functions and declare the constructor as private
// this ensures that instances cannot be created and we just work in main as follows: ScalarConverter::convert("1234");
// i also marked the other orthodox functions as private, as it doesn't seem to make sense to have them at all
// (without this they would created as public in the background)
class ScalarConverter
{
	private:
		std::string s;
		static bool isChar(std::string s);
		static bool isInt(std::string s);
		static bool isDouble_BaseRules(std::string s);
		static bool isFloat(std::string s);
		static bool isDouble(std::string s);
		static int convertToInt(std::string s);
		static float convertToFloat(std::string s);
		static double convertToDouble(std::string s);
		ScalarConverter();
		ScalarConverter(ScalarConverter &obj);
		ScalarConverter &operator=(ScalarConverter &obj);
		~ScalarConverter();		
	public:
		static void convert(std::string s);
};

#endif