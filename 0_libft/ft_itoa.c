/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:34:00 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:51:02 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length_of_str_as_int(int n)
{
	int		l;

	l = 0;
	if (n < 0)
	{
		n = n * -1;
		l++;
	}
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		start;
	int		l;
	char	*a;

	l = get_length_of_str_as_int(n);
	a = malloc(sizeof(char) * l + 1);
	if (n < 0)
	{
		a[0] = '-';
		n = n * -1;
		start = 1;
	}
	else
		start = 0;
	a[l] = '\0';
	l--;
	while (l >= start)
	{
		a[l] = 48 + (n % 10);
		n = n / 10;
		l--;
	}
	return (a);
}
