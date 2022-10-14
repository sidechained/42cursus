/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:50:32 by grm               #+#    #+#             */
/*   Updated: 2022/10/14 17:53:08 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR: Wrong number of arguments" << std::endl;
		return (0);
	}
	Karen karen;
	karen.complain(argv[1]);
	return (0);
}