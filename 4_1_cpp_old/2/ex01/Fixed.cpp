#include "Fixed.hpp"

// background:
// https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
// https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
// shifting an integer to the right by 1 bit position is equivalent to dividing the number by 2

// default constructor: initialises fixed point value to zero
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

// int constructor: converts int to correspondant fixed(8) point value
// (left shift value by 8 places)
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = (value << Fixed::numFractionalBits);
}

// float constructor: converts float to correspondant fixed(8) point value
// (left shift int 1 by 8 places then multiply by float value, then round)
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << Fixed::numFractionalBits));
}

// default destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = copy.getRawBits();
	return *this;	
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// converts the fixed point value to a floating point value
// (fixed point value [cast to float], divided by 1 left shift 8 places [cast to float])
float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << Fixed::numFractionalBits));
}

// converts the fixed point value to an integer value
// (right shift fixed point value eight places)
int Fixed::toInt(void) const
{
	return _fixedPointValue >> Fixed::numFractionalBits;
}

// not a member method:
// inserts a floating point representation of the fixed point value into the parameter output stream
std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}