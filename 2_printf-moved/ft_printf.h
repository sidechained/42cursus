/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:51:10 by gbooth            #+#    #+#             */
/*   Updated: 2022/12/26 16:53:26 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *format_str, ...);
int		ft_vprintf(const char *format_str, va_list ap);
void	ft_convert(const char *format_str, int *pos, int *len, va_list ap);
int		ft_convert_c(va_list ap);
int		ft_convert_s(va_list ap);
int		ft_convert_di(va_list ap);
int		ft_convert_p(va_list ap);
int		ft_convert_u(va_list ap);
int		ft_convert_x(const char format_str, va_list ap);

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_put_unsigned_nbr_base(unsigned long nbr, char *base);
void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, int *len);

char	*ft_uitoa(unsigned int n);

#endif