/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:47:32 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;
	size_t	i;

	s_cpy = (char *)s;
	i = 0;
	while (s_cpy[i] != '\0')
	{
		if (s_cpy[i] == (char)c)
			return (&s_cpy[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s_cpy[i + 1]);
	return (NULL);
}
