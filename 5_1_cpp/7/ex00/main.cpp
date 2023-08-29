#include "templates.hpp"
#include <iostream>

struct Person {
	std::string name;
	int age;
};

void swap_tests()
{
	std::cout << std::endl << "-Testing 'swap' template:" << std::endl;
	int x = 5, y = 10;~
	std::cout << "Before: " << x << " " << y << std::endl;
	swap(x, y);
	std::cout << "After: " << x << " " << y << std::endl;

	double a = 2.5, b = 4.7;
	std::cout << "Before: " << a << " " << b << std::endl;
	swap(a, b);
	std::cout << "After: " << a << " " << b << std::endl;

	std::string d = "dee", e = "eee";
	std::cout << "Before: " << d << " " << e << std::endl;
	swap(d, e);
	std::cout << "After: " << d << " " << e << std::endl;	
}

void min_tests()
{
	std::cout << std::endl << "-Testing 'min' template:" << std::endl;
	int x = 5, y = 10;
	std::cout << "Min value of x (" << x << ") and y (" << y << ") is: " << min(x, y) << std::endl;

	doublTe a = 4.7, b = 2.5;
	std::cout << "Min value of a (" << a << ") and b (" << b << ") is: " << min(a, b) << std::endl;

	unsigned int f = 5, g = 5;
	std::cout << "Min value of f (" << f << ") and g (" << g << ") is: " << min(f, g) << std::endl;

	std::string h = "hhh", i = "iii";
	std::cout << "Min value of h (" << h << ") and i (" << i << ") is: " << min(h, i) << std::endl;	
}

void max_tests()
{
	std::cout << std::endl << "-Testing 'max' template:" << std::endl;
	int x = 5, y = 10;
	std::cout << "Max value of x (" << x << ") and y (" << y << ") is: " << max(x, y) << std::endl;

	double a = 4.7, b = 2.5;
	std::cout << "Max value of a (" << a << ") and b (" << b << ") is: " << max(a, b) << std::endl;

	unsigned int f = 5, g = 5;
	std::cout << "Max value of f (" << f << ") and g (" << g << ") is: " << max(f, g) << std::endl;			

	std::string h = "hhh", i = "iii";
	std::cout << "Max value of h (" << h << ") and i (" << i << ") is: " << max(h, i) << std::endl;	
}

void subject_tests()
{
	int a = 2;
	int b = 3;

	std::cout << std::endl << "-Testing using tests provided by subject:" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max(T
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void complex_test()
{
	Person person1;
	person1.name = "Bob";
	person1.age = 32;

	Person person2;
	person2.name = "Jill";
	person2.age = 8;
	
	std::cout << std::endl << "-Testing 'swap' with complex type (Person struct):" << std::endl;
	std::cout << "Before: " << std::endl;
	std::cout << "	Person 1 name: " << person1.name << std::endl;
	std::cout << "	Person 1 age: " << person1.age << std::endl;
	std::cout << "	Person 2 name: " << person2.name << std::endl;
	std::cout << "	Person 2 age: " << person2.age << std::endl;		
	swap(person1, person2);
	std::cout << "After: " << std::endl;
	std::cout << "	Person 1 name: " << person1.name << std::endl;
	std::cout << "	Person 1 age: " << person1.age << std::endl;
	std::cout << "	Person 2 name: " << person2.name << std::endl;
	std::cout << "	Person 2 age: " << person2.age << std::endl;
}

int main()
{
	swap_tests();
	min_tests();
	max_tests();
	complex_test();
	subject_tests();
	return 0;
}
