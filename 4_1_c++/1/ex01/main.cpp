/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:01:55 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 12:29:35 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int		main(void)
{

	Zombie *horde;
	int N;
	int i;

	N = 5;
	horde = zombieHorde(N, "zombo");
	i = 0;
	while(i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}