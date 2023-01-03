/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:51:44 by gbooth            #+#    #+#             */
/*   Updated: 2022/12/26 17:37:41 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format_str, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format_str);
	len = ft_vprintf(format_str, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format_str, va_list ap)
{
	int	pos;
	int	len;

	pos = 0;
	len = 0;
	if (format_str == NULL)
		return (-1);
	while (format_str[pos])
	{
		if (format_str[pos] == '%')
		{
			pos++;
			ft_convert(format_str, &pos, &len, ap);
		}
		else
		{
			ft_putchar(format_str[pos]);
			pos++;
			len++;
		}
	}
	return (len);
}

void	ft_convert(const char *format_str, int *pos, int *len, va_list ap)
{
	if (format_str[*pos] == 'c')
		*len += ft_convert_c(ap);
	if (format_str[*pos] == 's')
		*len += ft_convert_s(ap);
	if (format_str[*pos] == 'd' || format_str[*pos] == 'i')
		*len += ft_convert_di(ap);
	if (format_str[*pos] == 'p')
		*len += ft_convert_p(ap);
	if (format_str[*pos] == 'u')
		*len += ft_convert_u(ap);
	if (format_str[*pos] == 'x' || format_str[*pos] == 'X')
		*len += ft_convert_x(format_str[*pos], ap);
	if (format_str[*pos] == 'c' || format_str[*pos] == 's' || \
		format_str[*pos] == 'd' || format_str[*pos] == 'i' || \
		format_str[*pos] == 'p' || format_str[*pos] == 'u' || \
		format_str[*pos] == 'x' || format_str[*pos] == 'X')
		(*pos)++;
	else if (format_str[*pos] == '%')
	{
		ft_putstr("%");
		(*pos)++;
		(*len)++;
	}
	else
		*len = -1;
}

int	ft_convert_c(va_list ap)
{
	ft_putchar(va_arg(ap, int));
	return (1);
}
