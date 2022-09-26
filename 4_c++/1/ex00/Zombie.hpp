/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:44:59 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 12:25:32 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <iostream> // cout

class Zombie {
	private:
		std::string	_name;
	public:
		// function prototypes:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
};

#endif