/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:51:44 by gbooth            #+#    #+#             */
/*   Updated: 2023/02/01 14:34:40 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format_str, ...)
{
	int		len;
	va_list	ap;

	len = 0;
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
		ft_convert_c(ap, len);
	if (format_str[*pos] == 's')
		ft_convert_s(ap, len);
	if (format_str[*pos] == 'd' || format_str[*pos] == 'i')
		ft_convert_di(ap, len);
	if (format_str[*pos] == 'p')
		ft_convert_p(ap, len);
	if (format_str[*pos] == 'u')
		ft_convert_u(ap, len);
	if (format_str[*pos] == 'x' || format_str[*pos] == 'X')
		ft_convert_x(format_str[*pos], ap, len);
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

void	ft_convert_c(va_list ap, int *len)
{
	ft_putchar(va_arg(ap, int));
	(*len)++;
}
