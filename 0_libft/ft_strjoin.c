/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:47:23 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NOTE: tried to use this in get_next_line, but it failed! More tests needed!

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	char			*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = 0;
	while (s1[l1] != '\0')
		l1++;
	l2 = 0;
	while (s2[l2] != '\0')
		l2++;
	ret = malloc(sizeof(char) * (l1 + l2));
	l2 = 0;
	while (s1[l2++] != '\0')
		ret[l2] = s1[l2];
	l2 = 0;
	while (s2[l2++] != '\0')
		ret[l1 + l2] = s2[l2];
	return (ret);
}
