/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/13 12:40:56 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	choose_mutex_order(t_phil *phil)
{
	if (phil->i % 2 == 0)
	{
		pthread_mutex_lock(phil->left_fork);
		printf("[%lld]	%i takes left fork\n", ts() - phil->start, phil->i);
		pthread_mutex_lock(phil->right_fork);
		printf("[%lld]	%i takes right fork\n", ts() - phil->start, phil->i);
	}
	else
	{
		pthread_mutex_lock(phil->right_fork);
		printf("[%lld]	%i takes right fork\n", ts() - phil->start, phil->i);
		pthread_mutex_lock(phil->left_fork);
		printf("[%lld]	%i takes left fork\n", ts() - phil->start, phil->i);
	}
}

void	*start_phil(void *void_phil)
{
	t_phil	*phil;

	phil = (t_phil *)void_phil;
	printf("[%lld]	%i is thinking\n", ts() - phil->start, phil->i);
	while (phil->end_reached == false)
	{
		choose_mutex_order(phil);
		printf("[%lld]	%i is eating\n", ts() - phil->start, phil->i);
		phil->time_last_eaten = ts();
		wait(phil->time_to_eat);
		pthread_mutex_unlock(phil->left_fork);
		pthread_mutex_unlock(phil->right_fork);
		phil->num_times_eaten++;
		if (phil->num_times_must_eat != 0
			&& phil->num_times_eaten >= phil->num_times_must_eat)
			return (NULL);
		printf("[%lld]	%i is sleeping\n", ts() - phil->start, phil->i);
		wait(phil->time_to_sleep);
	}
	return (NULL);
}

void	init_phs(int n_phs, char **argv, t_phil *phs, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < n_phs)
	{
		pthread_mutex_init(&forks[i], NULL);
		phs[i].i = i;
		phs[i].end_reached = false;
		phs[i].start = ts();
		phs[i].n_phs = n_phs;
		phs[i].time_to_die = ft_atoi(argv[2]);
		phs[i].time_to_eat = ft_atoi(argv[3]);
		phs[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5] != NULL)
			phs[i].num_times_must_eat = ft_atoi(argv[5]);
		else
			phs[i].num_times_must_eat = 0;
		phs[i].num_times_eaten = 0;
		phs[i].time_last_eaten = ts();
		phs[i].left_fork = &forks[i];
		phs[i].right_fork = &forks[(i + 1) % n_phs];
		pthread_create(&phs[i].tid, NULL, start_phil, &phs[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int				n_phs;
	int				i;
	t_phil			*phs;
	pthread_mutex_t	*forks;

	if (input_error_checking(argc, argv))
		return (1);
	n_phs = ft_atoi(argv[1]);
	phs = malloc(sizeof(t_phil) * n_phs);
	forks = malloc(sizeof(pthread_mutex_t) * n_phs);
	init_phs(n_phs, argv, phs, forks);
	create_diechk_threads(phs);
	i = 0;
	while (i < n_phs)
	{
		pthread_join(phs[i].tid, NULL);
		phs[i].end_reached = true;
		pthread_join(phs[i].diechk_tid, NULL);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(phs);
	free(forks);
	return (0);
}
