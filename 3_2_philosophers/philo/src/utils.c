/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/16 00:27:13 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// alt death check:
// i = 0;
// while (i < ((t_this *)this)->num_philos)
// {
// 	((t_this *)this)->philos[i].alive = false;
// 	// pthread_mutex_unlock(((t_this *)this)->philos[i].left_fork);
// 	// pthread_mutex_unlock(((t_this *)this)->philos[i].right_fork);
// 		free(this->forks);
// 	i++;
// }
// return (NULL);

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

void	*death_check_thread(void *void_this)
{
	int		i;
	t_this	*this;

	this = ((t_this *)void_this);
	while (1)
	{
		usleep(2);
		i = 0;
		while (i < this->num_philos)
		{
			if (ts() > this->philos[i].time_last_eaten
				+ this->philos[i].time_to_die)
			{
				printf("[%lld]	%i died\n", ts() - this->philos[i].start,
					this->philos[i].index);
				free(this->forks);
				free(this->philos);
				free(this);
				exit(0);
			}
			i++;
		}
	}
}
