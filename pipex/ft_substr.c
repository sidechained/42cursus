char *ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char *ret;
	unsigned int i;

	if (start < 0)
		return (NULL);
	if (len <= 0)
		return (NULL);
	while (start--)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	ret = malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		if (s[i] == '\0')
			return (NULL);
		ret[i] = s[i];
		i++;
	}
	return (ret);
}