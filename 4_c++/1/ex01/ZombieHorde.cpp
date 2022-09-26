/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:36:39 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 13:41:38 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i;
	Zombie *horde = new Zombie[N];
	std::string newName;

	i = 0;
	while(i < N)
	{
		newName = name;
		newName.push_back(i + '0');
		horde[i].setName(newName);
		i++;
	}
	return(horde);
}