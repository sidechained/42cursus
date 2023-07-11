/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/07/04 09:07:21 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&(philo->info->print));
	time = ts() - philo->info->start;
	if (philo->alive)
		printf("[%lld]	%d %s", ts() - 
			philo->info->start, philo->index + 1, str);
	pthread_mutex_unlock(&(philo->info->print));
}

int	check_for_invalid_args(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < ft_strlen(argv[i + 1]))
		{
			if (argv[i + 1][j] < '0' || argv[i + 1][j++] > '9')
			{
				printf("Error: Invalid argument(s)\n");
				return (1);
			}
		}
		if (j == 0)
		{
			printf("Error: Invalid argument(s)\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	input_error_checking(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("Error: There must be at least one philosopher\n");
		return (1);
	}
	check_for_invalid_args(argc, argv);
	return (0);
}

long long	ts(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	wait(long long time)
{
	long long	now;
	long long	then;

	then = ts();
	while (1)
	{
		now = ts();
		if (now - then >= time)
			return ;
		usleep(5);
	}
}
