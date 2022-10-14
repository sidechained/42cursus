/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:44:59 by grm               #+#    #+#             */
/*   Updated: 2022/09/27 08:14:39 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <iostream> // cout

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon();
		Weapon(std::string type);
		void	setType(std::string type);
		std::string	getType();		
};

#endif