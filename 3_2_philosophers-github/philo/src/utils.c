/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/19 10:44:24 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	input_error_checking(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i + 1]) < 0)
		{
			printf("Error: Invalid argument(s)\n");
			return (1);
		}
		i++;
	}
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

int	death_checker(t_this *this)
{
	int	i;

	i = 0;
	while (i < this->num_philos)
	{
		if (ts() > this->philos[i].time_last_eaten
			+ this->philos[i].time_to_die)
		{
			printf("[%lld]	%i died\n", ts() - this->philos[i].start,
				this->philos[i].index);
			if (this->num_philos == 1)
				pthread_mutex_unlock(this->philos[i].left_fork);
			i = 0;
			while (i < this->num_philos)
			{
				this->philos[i].alive = false;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring_thread(void *void_this)
{
	t_this	*this;
	int		i;

	this = ((t_this *)void_this);
	while (1)
	{
		usleep(2);
		i = 0;
		while (i < this->num_philos)
		{
			if (this->philos[i].finished_eating)
			{
				printf("[%lld]	%i finished eating\n", ts()
					- this->philos[i].start, this->philos[i].index);
				return (NULL);
			}
			i++;
		}
		if (death_checker(this))
			return (NULL);
	}
}
