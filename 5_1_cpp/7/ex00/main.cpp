#include "templates.hpp"
#include <iostream>

void subject_tests()
{
	int a = 2;
	int b = 3;

	std::cout << std::endl << "-Testing using tests provided by subject:" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main()
{
	{
		std::cout << std::endl << "-Testing 'swap' template:" << std::endl;
		int x = 5, y = 10;
		std::cout << "Before: " << x << " " << y << std::endl;
		swap(x, y);  // Compiler generates swap<int>(x, y)
		std::cout << "After: " << x << " " << y << std::endl;

		double a = 2.5, b = 4.7;
		std::cout << "Before: " << a << " " << b << std::endl;
		swap(a, b);  // Compiler generates swap<double>(a, b)
		std::cout << "After: " << a << " " << b << std::endl;
	}
	{
		std::cout << std::endl << "-Testing 'min' template:" << std::endl;
		int x = 5, y = 10;
		std::cout << "Min value of x (" << x << ") and y (" << y << ") is: " << min(x, y) << std::endl;
	
		double a = 4.7, b = 2.5;
		std::cout << "Min value of a (" << a << ") and b (" << b << ") is: " << min(a, b) << std::endl;

		unsigned int f = 5, g = 5;
		std::cout << "Min value of f (" << f << ") and g (" << g << ") is: " << min(f, g) << std::endl;		
	}
	{
		std::cout << std::endl << "-Testing 'max' template:" << std::endl;
		int x = 5, y = 10;
		std::cout << "Max value of x (" << x << ") and y (" << y << ") is: " << max(x, y) << std::endl;
	
		double a = 4.7, b = 2.5;
		std::cout << "Max value of a (" << a << ") and b (" << b << ") is: " << max(a, b) << std::endl;

		unsigned int f = 5, g = 5;
		std::cout << "Max value of f (" << f << ") and g (" << g << ") is: " << max(f, g) << std::endl;		
	}
	{
		subject_tests();
	}
	return 0;
}