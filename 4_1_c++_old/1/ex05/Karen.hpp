/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:20 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 17:08:02 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP

# define KAREN_HPP

#include <iostream> // cout

class Karen {
	private:
		void	(Karen::*complaint[4])( void );
		std::string complaintLevels[4];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Karen(void);
		void complain(std::string level);
};

#endif