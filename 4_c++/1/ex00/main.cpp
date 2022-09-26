/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:01:55 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 12:26:06 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// function prototypes:
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

// example of allocating on stack (lines 22-24) vs heap (line 25)
int		main(void)
{
	Zombie	*z = newZombie("Alex");
	z->announce();
	delete z;
	randomChump("Bruno");
	return (0);
}