#include "Fixed.hpp"

// default constructor
Fixed::Fixed()
{
	this->_fixedPointValue = 0;
}

// int constructor
Fixed::Fixed(const int value)
{
	this->_fixedPointValue = (value << Fixed::numFractionalBits);
}

// float constructor
Fixed::Fixed(const float value)
{
	this->_fixedPointValue = roundf(value * (1 << Fixed::numFractionalBits));
}

// default destructor
Fixed::~Fixed()
{
}

// copy constructor
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

// copy assignment operator
Fixed	&Fixed::operator=(const Fixed &copy)
{
	this->_fixedPointValue = copy.getRawBits();
	return (*this);	
}

bool Fixed::operator>(const Fixed &copy) const
{
	return (this->getRawBits() > copy.getRawBits());
}

bool Fixed::operator<(const Fixed &copy) const
{
	return (this->getRawBits() < copy.getRawBits());
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return (this->getRawBits() >= copy.getRawBits());
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return (this->getRawBits() <= copy.getRawBits());
}

bool Fixed::operator==(const Fixed &copy) const
{
	return (this->getRawBits() == copy.getRawBits());
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return (this->getRawBits() != copy.getRawBits());
}

// set raw bits to:
// this instances' raw bits value (left side of operator)
// +
// raw bits value of instance to add (right side of operator)
Fixed Fixed::operator+(const Fixed &copy) const
{
	// EXPLAIN THIS:
	Fixed val(*this);

	val.setRawBits(this->getRawBits() + copy.getRawBits());
	return (val);
}

// set raw bits to:
// this instances' raw bits value (left side of operator)
// -
// raw bits value of instance to add (right side of operator)
Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() - copy.getRawBits());
	return (val);
}

// set raw bits to:
// this instances' raw bits value (converted to long)
// *
// raw bits value of instance to copy (converted to long)
// result of this divided by '1' shifted 8 places to left
Fixed Fixed::operator*(const Fixed &copy) const
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)copy.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::numFractionalBits));
	return (val);
}

// set raw bits to:
// '1' shifted 8 places to left, multipied by this instances' raw bits value
// result of this divided by raw bits value of instance to copy (converted to long)
Fixed Fixed::operator/(const Fixed &copy) const
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)copy.getRawBits());
	val.setRawBits((tmp1 * (1 << Fixed::numFractionalBits)) / tmp2);
	return (val);
}

// pre-increment
Fixed Fixed::operator++()
{
	this->_fixedPointValue++;
	return(*this);
}

// post-increment
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

// pre-decrement
Fixed Fixed::operator--()
{
	this->_fixedPointValue--;
	return(*this);
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

int Fixed::getRawBits(void) const
{
	return(this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << Fixed::numFractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> Fixed::numFractionalBits);
}

Fixed &Fixed::min(Fixed &fpv1, Fixed &fpv2)
{
	if (fpv1 < fpv2)
		return(fpv1);
	else
		return(fpv2);
}

const Fixed &Fixed::min(const Fixed &fpv1, const Fixed &fpv2)
{
	if (fpv1 < fpv2)
		return(fpv1);
	else
		return(fpv2);
}

Fixed &Fixed::max(Fixed &fpv1, Fixed &fpv2)
{
	if (fpv1 > fpv2)
		return(fpv1);
	else
		return(fpv2);
}

const Fixed &Fixed::max(const Fixed &fpv1, const Fixed &fpv2)
{
	if (fpv1 > fpv2)
		return(fpv1);
	else
		return(fpv2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);	
}