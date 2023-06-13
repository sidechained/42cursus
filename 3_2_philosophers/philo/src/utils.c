/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/13 12:40:56 by gbooth           ###   ########.fr       */
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

void	create_diechk_threads(t_phil *phs)
{
	int				i;

	i = 0;
	while (i < phs->n_phs)
	{	
		pthread_create(&phs[i].diechk_tid, NULL, start_diechk, (void *)&phs[i]);
		i++;
	}
}

void	*start_diechk(void *void_phil)
{
	t_phil	*phil;
	int		i;

	phil = (t_phil *)void_phil;
	while (phil->end_reached == false)
	{
		i = 0;
		wait(5);
		if ((ts() - phil->time_last_eaten > phil->time_to_die))
		{
			printf("[%lld]	%i died\n", ts() - phil->start, phil->i);
			pthread_join(phil->diechk_tid, NULL);
			phil->end_reached = true;
			exit(0);
		}
		i++;
	}
	return (NULL);
}
