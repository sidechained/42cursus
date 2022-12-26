/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:50:56 by gbooth            #+#    #+#             */
/*   Updated: 2022/12/26 16:49:30 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	ft_putstr(s);
	return (ft_strlen(s));
}

int	ft_convert_di(va_list ap)
{
	char	*di_str;

	di_str = ft_itoa(va_arg(ap, int));
	ft_putstr(di_str);
	return (ft_strlen(di_str));
}

int	ft_convert_p(va_list ap)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	write(2, "0x", 2);
	len = 2 + ft_put_unsigned_nbr_base((unsigned long)va_arg(ap, char *), base);
	return (len);
}

int	ft_convert_u(va_list ap)
{
	char	*u_str;

	u_str = ft_uitoa(va_arg(ap, unsigned int));
	ft_putstr(u_str);
	return (ft_strlen(u_str));
}

int	ft_convert_x(const char format_str, va_list ap)
{
	char	*base;
	int		len;

	if (format_str == 'x')
		base = "0123456789abcdef";
	if (format_str == 'X')
		base = "0123456789ABCDEF";
	len = ft_put_unsigned_nbr_base(va_arg(ap, unsigned int), base);
	return (len);
}
