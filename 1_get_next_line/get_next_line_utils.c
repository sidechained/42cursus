#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_;
	size_t	i;

	s_ = (char *)s;
	i = 0;
	c = c % 256;
	if (c == 0)
		return (&s_[ft_strlen(s)]);
	while (s_[i])
	{
		if (s_[i] == (char)c)
			return (&s_[i]);
		i++;
	}
	return (NULL);
}

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

// ft_strjoin
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

// ft_substr
static char	*make_new_substr(char const *s, uint len)
{
	char	*ret;
	uint	i;

	ret = NULL;
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

char	*malloc_empty_string(void)
{
	char			*ret;

	ret = malloc(sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, uint start, size_t len)
{
	char	*ret;

	ret = NULL;
	if ((start == UINT_MAX && len == ULONG_MAX) || len == 0)
		return (malloc_empty_string());
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	while (start--)
	{
		if (*s == '\0')
			return (malloc_empty_string());
		s++;
	}
	ret = make_new_substr(s, len);
	return (ret);
}
