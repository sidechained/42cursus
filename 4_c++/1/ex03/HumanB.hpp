/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:29 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 15:34:40 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

#include <iostream> // cout
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon _weapon;
		std::string	_name;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon weapon);
		Weapon	getWeapon(void);
		void	attack();
};

#endif