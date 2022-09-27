/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:12:04 by grm               #+#    #+#             */
/*   Updated: 2022/09/27 08:32:25 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream> // cout

class Fixed {
	private:
		int fpv; // fixed point value
		static const int numFractionalBits; // always 8
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(Fixed const &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif