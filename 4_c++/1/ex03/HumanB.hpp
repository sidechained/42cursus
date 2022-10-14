/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:29 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 13:56:53 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

#include <iostream> // cout
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon *_weapon;		
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
};

#endif