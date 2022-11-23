/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:51:30 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:47:35 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**alloc_array_of_splits(char const *s, char c)
{
	int		i;
	int		no_splits;
	char	**splits;

	i = 0;
	no_splits = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			no_splits++;
		i++;
	}
	splits = malloc(sizeof(char *) * (no_splits + 2));
	return (splits);
}

char	*split_it(char const *s, int prev_i, int i)
{
	char	*split;
	int		j;

	split = malloc(sizeof(char) * (i - prev_i + 1));
	j = 0;
	while (prev_i < i)
	{
		split[j] = s[prev_i];
		prev_i++;
		j++;
	}
	split[j + 1] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		prev_i;	
	int		no_splits;
	char	**splits;

	splits = alloc_array_of_splits(s, c);
	i = 0;
	no_splits = 0;
	prev_i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			splits[no_splits] = split_it(s, prev_i, i);
			prev_i = i;
			no_splits++;
		}
		i++;
	}
	prev_i++;
	splits[no_splits] = split_it(s, prev_i, i);
	splits[++no_splits] = NULL;
	return (splits);
}
