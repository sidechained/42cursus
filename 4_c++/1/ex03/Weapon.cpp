/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:09:21 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 13:43:01 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	// check how others implemented this
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const	&Weapon::getType() const
{
	return(this->_type);
}