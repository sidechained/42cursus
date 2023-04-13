/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/04/05 23:30:13 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	death_check(t_phil *phil)
{
	long long	now;

	now = get_timestamp_ms();
	// printf("%i %lld\n", phil->index, now - phil->time_last_eaten);
	if ((now - phil->time_last_eaten) > phil->time_to_die)
	{
		printf("%lld %i died\n", get_timestamp_ms(), phil->index);
		return (1);
	}
	return (0);
}

void	loop_phil(t_phil *phil)
{
	while (1)
	{
		pthread_mutex_lock(phil->left_fork);
		printf("%lld %i has taken a fork\n", get_timestamp_ms(), phil->index);
		pthread_mutex_lock(phil->right_fork);
		printf("%lld %i has taken a fork\n", get_timestamp_ms(), phil->index);
		printf("%lld %i is eating\n", get_timestamp_ms(), phil->index);
		phil->time_last_eaten = get_timestamp_ms();
		if (sleepytime(phil->time_to_eat, phil))
			return ;
		pthread_mutex_unlock(phil->left_fork);
		pthread_mutex_unlock(phil->right_fork);
		phil->num_times_eaten++;
		if (phil->num_times_must_eat != 0
			&& phil->num_times_eaten >= phil->num_times_must_eat)
			return ;
		printf("%lld %i is sleeping\n", get_timestamp_ms(), phil->index);
		if (sleepytime(phil->time_to_sleep, phil))
			return ;
	}
}

void	*start_phil(void *void_phil)
{
	t_phil	*phil;

	phil = (t_phil *)void_phil;
	printf("%lld %i is thinking\n", get_timestamp_ms(), phil->index);
	if (phil->num_philos == 1)
	{
		printf("%lld %i has taken a fork\n", get_timestamp_ms(), phil->index);
		while (1)
		{
			if (death_check(phil))
				exit (0);
		}
	}
	loop_phil(phil);
	exit (0);
}

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

int	main(int argc, char **argv)
{
	int	num_philos;
	int	i;
	t_phil	*phils;
	pthread_mutex_t	*forks;

	if (input_error_checking(argc, argv))
		return (1);
	num_philos = ft_atoi(argv[1]);
	phils = malloc(sizeof(t_phil) * num_philos);
	forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		phils[i].index = i;
		phils[i].num_philos = num_philos;
		phils[i].time_to_die = ft_atoi(argv[2]);
		phils[i].time_to_eat = ft_atoi(argv[3]);
		phils[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			phils[i].num_times_must_eat = ft_atoi(argv[5]);
		else
			phils[i].num_times_must_eat = 0;
		phils[i].num_times_eaten = 0;
		phils[i].time_last_eaten = get_timestamp_ms();
		phils[i].left_fork = &forks[i];
		phils[i].right_fork = &forks[(i + 1) % num_philos];
		pthread_create(&phils[i].thread_id, NULL, start_phil, &phils[i]);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_join(phils[i].thread_id, NULL);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(phils);
	free(forks);
	return (0);
}
