/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:01:55 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 12:23:59 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int		main(void)
{
	// example of allocating on stack:
	Zombie	*z = newZombie("Alex");
	z->announce();
	delete z;
	// example of allocating on heap:
	randomChump("Bruno");
	return (0);
}