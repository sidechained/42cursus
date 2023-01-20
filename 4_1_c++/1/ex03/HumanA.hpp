/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:29 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 13:47:54 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

#include <iostream> // cout
#include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon &_weapon;		
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();
};

#endif