/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/03/29 15:26:39 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}

static int	convert_ascii_to_integer(char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] != '\0')
	{	
		if (!ft_isdigit(nptr[i]))
			break ;
		result = result * 10;
		result = result + nptr[i] - '0';
		i++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	char	*nptr_;
	int		result;
	bool	is_minus;

	is_minus = false;
	nptr_ = (char *)nptr;
	while (*nptr_ == ' ' || *nptr_ == '\t' || *nptr_ == '\r'
		|| *nptr_ == '\n' || *nptr_ == '\v' || *nptr_ == '\f')
		nptr_++;
	if (*nptr_ == '+' || *nptr_ == '-')
	{
		if (*nptr_ == '-')
			is_minus = true;
		nptr_++;
	}
	result = 0;
	result = convert_ascii_to_integer(nptr_);
	if (is_minus)
		result = result * -1;
	return (result);
}

long long	get_timestamp_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	sleepytime(long long time, t_phil *phil)
{
	long long	now;
	long long	then;

	then = get_timestamp_ms();
	while (1)
	{
		now = get_timestamp_ms();
		if (death_check(phil))
			return (1);
		if (now - then >= time)
			return (0);
		usleep(5);
	}
}
