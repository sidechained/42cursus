/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:10:26 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 22:18:25 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor: initialises fixed point value to zero
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

// int constructor: converts int to correspondant fixed(8) point value
// (left shift value by 8 places)
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = (value << Fixed::numFractionalBits);
}

// float constructor: converts float to correspondant fixed(8) point value
// (left shift int 1 by 8 places then multiply by float value, then round)
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << Fixed::numFractionalBits));
}

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
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	return (*this);	
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
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
	return (this->_fixedPointValue >> Fixed::numFractionalBits);
}

// not a member method:
// inserts a floating point representation of the fixed point value into the parameter output stream
std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);	
}