/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:26:14 by jaeskim           #+#    #+#             */
/*   Updated: 2022/11/13 11:48:18 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** ft_strtrim - remove leading and trailing charset(char const *set)
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	while (*s1 && strchr(set, *s1) != 0)
		s1++;
	len = strlen(s1);
	while (len && s1[len - 1] && strchr(set, s1[len - 1]) != 0)
		len--;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
