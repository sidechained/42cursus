/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/19 10:42:50 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	lock_in_order(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		if (philo->alive)
			printf("[%lld]	%i takes left fork\n", ts() - philo->start,
				philo->index);
		pthread_mutex_lock(philo->right_fork);
		if (philo->alive)
			printf("[%lld]	%i takes right fork\n", ts() - philo->start,
				philo->index);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (philo->alive)
			printf("[%lld]	%i takes right fork\n", ts() - philo->start,
				philo->index);
		pthread_mutex_lock(philo->left_fork);
		if (philo->alive)
			printf("[%lld]	%i takes left fork\n", ts() - philo->start,
				philo->index);
	}
	if (philo->alive)
		printf("[%lld]	%i is eating\n", ts() - philo->start, philo->index);
}

void	unlock_in_order(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	*philo_thread(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	printf("[%lld]	%i is thinking\n", ts() - philo->start, philo->index);
	while (philo->alive)
	{
		lock_in_order(philo);
		philo->time_last_eaten = ts();
		wait(philo->time_to_eat);
		unlock_in_order(philo);
		if (philo->alive == false)
			break ;
		philo->num_times_eaten++;
		if (philo->num_times_must_eat != 0
			&& philo->num_times_eaten >= philo->num_times_must_eat)
		{
			philo->finished_eating = true;
			break ;
		}
		printf("[%lld]	%i is sleeping\n", ts() - philo->start, philo->index);
		wait(philo->time_to_sleep);
	}
	return (NULL);
}

//pthread_mutex_init(&this->forks[i], NULL);
void	init_and_start_philos(char **argv, t_this *this)
{
	int	i;

	i = 0;
	while (i < this->num_philos)
	{		
		this->philos[i].index = i;
		this->philos[i].time_to_die = ft_atoi(argv[2]);
		this->philos[i].time_to_eat = ft_atoi(argv[3]);
		this->philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5] != NULL)
			this->philos[i].num_times_must_eat = ft_atoi(argv[5]);
		else
			this->philos[i].num_times_must_eat = 0;
		this->philos[i].num_times_eaten = 0;
		this->philos[i].start = ts();
		this->philos[i].time_last_eaten = ts();
		this->philos[i].alive = true;
		this->philos[i].finished_eating = false;
		this->philos[i].left_fork = &this->forks[i];
		this->philos[i].right_fork = &this->forks[(i + 1) % this->num_philos];
		pthread_create(&this->philos[i].tid, NULL, philo_thread,
			(void *)&this->philos[i]);
		i++;
	}	
}

int	main(int argc, char **argv)
{
	t_this	*this;
	int		i;

	if (input_error_checking(argc, argv))
		return (1);
	this = malloc(sizeof(t_this));
	this->num_philos = ft_atoi(argv[1]);
	this->philos = malloc(sizeof(t_philo) * this->num_philos);
	this->forks = ft_calloc(this->num_philos, sizeof(pthread_mutex_t));
	init_and_start_philos(argv, this);
	pthread_create(&this->monitor_tid, NULL, monitoring_thread, (void *)this);
	pthread_join(this->monitor_tid, NULL);
	i = 0;
	while (i < this->num_philos)
	{
		pthread_join(this->philos[i].tid, NULL);
		i++;
	}
	free(this->forks);
	free(this->philos);
	free(this);
}
