/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:10:28 by grm               #+#    #+#             */
/*   Updated: 2022/09/27 08:34:49 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// To define a fixed point type conceptually, all we need are two parameters:
// - width of the number representation, and
// - binary point position within the number

// From now on, each class you write MUST be in orthodox canonical form:
// - at least one default constructor
// - a copy contructor
// - an assignation operator overload
// - a destructor

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}