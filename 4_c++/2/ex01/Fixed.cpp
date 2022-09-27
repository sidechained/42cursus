/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:10:26 by grm               #+#    #+#             */
/*   Updated: 2022/09/27 11:15:28 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
	//converts int to the correspondant fixed(8) point value
	//The fractional bits value is initialized like in ex00.
	std::cout << "Int constructor called" << std::endl;
	// EXPLAIN THIS:
	this->_fixedPointValue = (value << Fixed::numFractionalBits);
}

Fixed::Fixed(const float value)
{
	// converts it to the correspondant fixed(8) point value.
    // The fractional bits value is initialized like in ex00.
	std::cout << "Float constructor called" << std::endl;
	// EXPLAIN THIS:
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

void Fixed::setRawBits(int const raw )
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	// converts the fixed point value to a floating point value.
	// EXPLAIN THIS:
	return ((float)this->_fixedPointValue / (float)(1 << Fixed::numFractionalBits));
}

int Fixed::toInt(void) const
{
	// converts the fixed point value to an integer value.
	// EXPLAIN THIS:	
	return (this->_fixedPointValue >> Fixed::numFractionalBits);
}

// not a member method:
// inserts a floating point representation of the fixed point value into the parameter output stream.
std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);	
}