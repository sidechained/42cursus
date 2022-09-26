/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:04:35 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 12:08:32 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// heap: the destructor is called (and presumably memory freed) on reaching function end
void	randomChump(std::string name)
{
	Zombie	z = Zombie(name);
	z.announce();
}