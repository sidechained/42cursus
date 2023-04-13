/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:27:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/01/09 08:42:09 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dupstr;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dupstr = malloc(sizeof (char) * i + 1);
	if (!dupstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// for ft_strjoin
static char	*join_strs(char const *s1, char const *s2, uint l1, uint l2)
{
	char			*ret;

	ret = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!ret)
		return (NULL);
	l1 = 0;
	while (s1[l1] != '\0')
	{
		ret[l1] = s1[l1];
		l1++;
	}
	l2 = 0;
	while (s2[l2] != '\0')
	{
		ret[l1 + l2] = s2[l2];
		l2++;
	}
	ret[l1 + l2] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	uint	l1;
	uint	l2;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = 0;
	while (s1[l1] != '\0')
		l1++;
	l2 = 0;
	while (s2[l2] != '\0')
		l2++;
	ret = join_strs(s1, s2, l1, l2);
	return (ret);
}

char	*ft_substr(char const *s, uint start, size_t len)
{
	char	*ret;
	uint	i;

	if ((start == UINT_MAX && len == ULONG_MAX) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	while (start--)
	{
		if (*s++ == '\0')
			return (ft_strdup(""));
	}
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (s[i] == '\0')
			return (ret);
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
