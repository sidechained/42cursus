/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:10:26 by grm               #+#    #+#             */
/*   Updated: 2022/09/27 13:38:05 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = (value << Fixed::numFractionalBits);
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << Fixed::numFractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Assignation operator called" << std::endl;
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

Fixed Fixed::operator+(const Fixed &copy) const
{
	// EXPLAIN THIS:
	Fixed val(*this);

	val.setRawBits(this->getRawBits() + copy.getRawBits());
	return (val);
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() - copy.getRawBits());
	return (val);
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	// EXPLAIN THIS:	
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)copy.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::numFractionalBits));
	return (val);
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)copy.getRawBits());
	val.setRawBits((tmp1 * (1 << Fixed::numFractionalBits)) / tmp2);
	return (val);
}

Fixed Fixed::operator++()
{
	this->_fixedPointValue++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	// EXPLAIN THIS:
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->_fixedPointValue--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw )
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

Fixed &Fixed::max(Fixed &fpv1, Fixed &fpv2)
{
	if (fpv1 > fpv2)
		return(fpv1);
	else
		return(fpv2);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);	
}