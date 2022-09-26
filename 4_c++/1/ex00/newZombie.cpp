/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:03:42 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 12:08:34 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// stack: return pointer to new Zombie object
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}