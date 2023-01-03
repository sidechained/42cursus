/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:50:55 by gbooth            #+#    #+#             */
/*   Updated: 2022/12/26 16:00:32 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, int *result_len)
{
	if (nbr < ft_strlen(base))
	{
		ft_putchar(base[nbr]);
		(*result_len)++;
		return ;
	}
	ft_put_unsigned_long_nbr(nbr / ft_strlen(base), base, result_len);
	ft_put_unsigned_long_nbr(nbr % ft_strlen(base), base, result_len);
}

int	ft_put_unsigned_nbr_base(unsigned long nbr, char *base)
{
	int	result_len;

	result_len = 0;
	ft_put_unsigned_long_nbr(nbr, base, &result_len);
	return (result_len);
}
