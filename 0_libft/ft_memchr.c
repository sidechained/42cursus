/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:07:50 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:50:16 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	size_t			i;

	s_cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return (&s_cpy[i]);
		i++;
	}
	return (NULL);
}
