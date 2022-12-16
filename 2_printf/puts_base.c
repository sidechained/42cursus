int	ft_get_base_length(char *base)
{
	int	l;

	l = 0;
	while (base[l] != '\0')
		l++;
	return (l);
}

// check if base:empty or size 1, has dup char, has +/-/whitespace
int	ft_check_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (0);
		count = 0;
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j++])
			{
				count++;
				if (count > 1)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

void	ft_put_unsigned_nbr_base(unsigned long nbr, char *base)
{
	unsigned long	base_length;

	base_length = ft_get_base_length(base);
	if (base_length <= 1)
		return ;
	if (ft_check_base(base) == 0)
		return ;
	ft_put_unsigned_long_nbr(nbr, base, base_length);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = ft_get_base_length(base);
	if (nbr == -2147483648)
		return ;
	if (base_length <= 1)
		return ;
	if (ft_check_base(base) == 0)
		return ;
	ft_putnbr(nbr, base, base_length);
}