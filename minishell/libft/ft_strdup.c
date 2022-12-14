/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/08/20 23:29:09 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dupstr;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dupstr = (char *) malloc(sizeof (char) * i + 1);
	i = 0;
	while (s[i] != '\0')
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}
