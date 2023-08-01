#include "Fixed.hpp"

void	my_extra_tests()
{
	Fixed c (42.42f);
	Fixed d (42);

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << (c > d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << (c == d) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;
	std::cout << ++d << std::endl;
	d++;
	std::cout << d << std::endl;
	std::cout << --d << std::endl;
	d--;
	std::cout << d << std::endl;
	// non const
	std::cout << c.min( c, d ) << std::endl;
	std::cout << c.max( c, d ) << std::endl;

	Fixed const e (1.5f);
	Fixed const f (1);

	// const
	std::cout << Fixed::min( e, f ) << std::endl;
	std::cout << Fixed::max( e, f ) << std::endl;	
}

int main()
{
	Fixed 		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Subject tests:" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "My extra tests:" << std::endl;

	my_extra_tests();

	return 0;
}