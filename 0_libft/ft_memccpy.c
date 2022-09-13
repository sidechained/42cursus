/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:07:58 by gbooth            #+#    #+#             */
/*   Updated: 2022/08/20 23:29:00 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*c_src;
	char			*c_dest;
	unsigned int	i;

	c_src = (char *)src;
	c_dest = (char *)dest;
	i = 0;
	while (i < n)
	{		
		if (c_src[i] == (char)c)
			return (&c_dest[i + 1]);
		c_dest[i] = c_src[i];
		i++;
	}
	return (NULL);
}
