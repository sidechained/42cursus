/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:50:56 by gbooth            #+#    #+#             */
/*   Updated: 2023/02/01 14:34:35 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(va_list ap, int *len)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	ft_putstr(s);
	*len += ft_strlen(s);
}

void	ft_convert_di(va_list ap, int *len)
{
	char			*di_str;
	int				value;

	value = va_arg(ap, int);
	di_str = ft_itoa(value);
	ft_putstr(di_str);
	*len += ft_strlen(di_str);
	free(di_str);
}

void	ft_convert_p(va_list ap, int *len)
{
	char			*base;
	unsigned long	value;

	value = va_arg(ap, unsigned long);
	base = "0123456789abcdef";
	if (value == 0)
	{
		ft_putstr("(nil)");
		*len += 5;
		return ;
	}
	ft_putstr("0x");
	*len += 2 + ft_put_unsigned_nbr_base(value, base);
}

void	ft_convert_u(va_list ap, int *len)
{
	char			*u_str;

	u_str = ft_uitoa(va_arg(ap, unsigned int));
	ft_putstr(u_str);
	*len += ft_strlen(u_str);
	free(u_str);
}

void	ft_convert_x(const char format_str, va_list ap, int *len)
{
	char			*base;
	unsigned int	value;

	if (format_str == 'x')
		base = "0123456789abcdef";
	if (format_str == 'X')
		base = "0123456789ABCDEF";
	value = va_arg(ap, unsigned int);
	*len += ft_put_unsigned_nbr_base(value, base);
}
