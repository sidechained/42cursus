/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/28 09:06:00 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*ret;
	unsigned int	i;

	if (start < 0)
		return (NULL);
	if (len < 0)
		return (NULL);
	if (len == 0)
		return ("");	
	if (len > strlen(s))
		len = strlen(s);
	while (start--)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	ret = malloc(sizeof(char) * len);
	if (!ret)
	{
		return(NULL);
	}
	i = 0;
	while (i < len)
	{
		if (s[i] == '\0')
		{
			return (ret);
		}
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
