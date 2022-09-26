/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:13:08 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 16:25:22 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int		main(void)
{
	// std::string type;
	// Weapon weapon1("sword");

	// type = weapon1.getType();
	// std::cout << type << std::endl;
	// HumanA humanA("tim", weapon1.getType());
	// humanA.attack();

	// HumanB humanB1("kim");
	// std::cout << humanB1.getWeaponType() << std::endl;
	// humanB1.attack();	

	// HumanB humanB2("dave");
	// humanB2.setWeaponType("gun");
	// std::cout << humanB2.getWeaponType() << std::endl;
	// humanB2.attack();	

	// Weapon        club = Weapon("crude spiked club");
	// HumanA bob("Bob", club);
	// bob.attack();
	// club.setType("some other type of club");
	// bob.attack();

	Weapon 	club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	return (0);
}