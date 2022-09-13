/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/08/20 23:29:08 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convert_ascii_to_integer(char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] != '\0')
	{	
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
		result = result * 10;
		result = result + nptr[i] - '0';
		i++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	char	*nptr_cpy;
	int		result;
	int		minus_count;

	nptr_cpy = (char *)nptr;
	while (*nptr_cpy == ' ' || *nptr_cpy == '\t' || *nptr_cpy == '\r'
		|| *nptr_cpy == '\n' || *nptr_cpy == '\v' || *nptr_cpy == '\f')
		nptr_cpy++;
	minus_count = 0;
	while (*nptr_cpy == '-' || *nptr_cpy == '+')
	{
		if (*nptr_cpy == '-')
			minus_count++;
		nptr_cpy++;
	}
	result = 0;
	result = convert_ascii_to_integer(nptr_cpy);
	if (minus_count % 2 == 1)
		result = result * -1;
	return (result);
}
