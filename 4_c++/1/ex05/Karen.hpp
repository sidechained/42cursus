/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:20 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 21:14:19 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP

# define KAREN_HPP

#include <iostream> // cout

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3

class Karen {
	private:
		std::string levels[4];
		void *func_ptrs[4];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Karen(void);
		void complain(std::string level);
};

#endif