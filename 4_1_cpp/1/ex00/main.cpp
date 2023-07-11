/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:01:55 by grm               #+#    #+#             */
/*   Updated: 2023/07/09 21:00:38 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int		main(void)
{
	std::cout << "Using newZombie function to create a zombie, name and return it (stack)\n";
	Zombie	*z = newZombie("Alex");
	z->announce();
	delete z;
	std::cout << "\nUsing randomChump function to create a zombie, name and have it announce itself (heap)\n";
	randomChump("Bruno");
	return (0);
}