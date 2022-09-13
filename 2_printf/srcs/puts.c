#include "puts.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nbr, char *base, int base_length)
{
	int	i;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		ft_putnbr(nbr, base, base_length);
	}
	else if (nbr <= base_length)
	{	
		i = 0;
		while (i < nbr)
		{
			i++;
		}
		ft_putchar(base[i]);
	}
	else
	{
		ft_putnbr(nbr / base_length, base, base_length);
		ft_putnbr(nbr % base_length, base, base_length);
	}
}

void	ft_put_unsigned_nbr(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_put_unsigned_nbr(nb / 10);
		ft_put_unsigned_nbr(nb % 10);
	}
}

void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, unsigned long base_length)
{
	unsigned long	i;

 	if (nbr <= base_length)
	{	
		i = 0;
		while (i < nbr)
		{
			i++;
		}
		ft_putchar(base[i]);
	}
	else
	{
		ft_put_unsigned_long_nbr(nbr / base_length, base, base_length);
		ft_put_unsigned_long_nbr(nbr % base_length, base, base_length);
	}
}