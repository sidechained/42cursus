/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:47:12 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*big_cpy;
	size_t		i;
	int			j;

	big_cpy = (char *)big;
	i = 0;
	if (little[i] == '\0')
		return (&big_cpy[i]);
	while (big_cpy[i] != '\0' && i < len)
	{
		j = 0;
		while (big_cpy[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return (&big_cpy[i]);
		}
		i++;
	}
	return (0);
}
