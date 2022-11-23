/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:47:04 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trim_from_start(char const *s1, char const *set, int s1_i, int start)
{
	int		found;	
	int		set_i;

	while (s1[s1_i] != '\0')
	{
		found = 0;
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (s1[s1_i] == set[set_i])
			{
				start++;
				s1_i++;
				found = 1;
				return (start);
			}
			set_i++;
		}
		if (found == 0)
			return (start);
	}
	return (start);
}

int	trim_from_end(char const *s1, char const *set, int s1_i, int start)
{
	int		found;
	int		set_i;
	int		end;

	end = s1_i;
	while (s1_i > start)
	{
		found = 0;
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (s1[s1_i] == set[set_i])
			{
				end--;
				s1_i--;
				found = 1;
				return (end);
			}
			set_i++;
		}
		if (found == 0)
			return (end);
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_i;
	int		start;
	int		end;
	int		ret_i;
	char	*ret;

	s1_i = 0;
	start = 0;
	end = 0;
	start = trim_from_start(s1, set, s1_i, start);
	s1_i = 0;
	while (s1[s1_i] != '\0')
		s1_i++;
	s1_i--;
	end = trim_from_end(s1, set, s1_i, start);
	ret = malloc(end - start);
	ret_i = 0;
	s1_i = start;
	while (s1_i < end)
	{
		ret[ret_i] = s1[s1_i];
		ret_i++;
		s1_i++;
	}
	return (ret);
}
