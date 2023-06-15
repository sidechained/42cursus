/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/16 00:26:51 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	switch_mutex(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("[%lld]	%i takes left fork\n", ts() - philo->start,
			philo->index);
		pthread_mutex_lock(philo->right_fork);
		printf("[%lld]	%i takes right fork\n", ts() - philo->start,
			philo->index);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printf("[%lld]	%i takes right fork\n", ts() - philo->start,
			philo->index);
		pthread_mutex_lock(philo->left_fork);
		printf("[%lld]	%i takes left fork\n", ts() - philo->start,
			philo->index);
	}	
}

void	*philo_thread(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	printf("[%lld]	%i is thinking\n", ts() - philo->start, philo->index);
	while (1)
	{
		switch_mutex(philo);
		printf("[%lld]	%i is eating\n", ts() - philo->start, philo->index);
		philo->time_last_eaten = ts();
		wait(philo->time_to_eat);
		if (philo->alive == false)
			break ;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->num_times_eaten++;
		if (philo->num_times_must_eat != 0
			&& philo->num_times_eaten >= philo->num_times_must_eat)
			break ;
		printf("[%lld]	%i is sleeping\n", ts() - philo->start, philo->index);
		wait(philo->time_to_sleep);
		if (philo->alive == false)
			break ;
	}
	return (NULL);
}

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
		this->philos[i].left_fork = &this->forks[i];
		this->philos[i].right_fork = &this->forks[(i + 1) % this->num_philos];
		pthread_mutex_init(&this->forks[i], NULL);
		pthread_create(&this->philos[i].tid, NULL, philo_thread,
			(void *)&this->philos[i]);
		i++;
	}	
}

void	block_threads(t_this *this)
{
	int	i;

	i = 0;
	while(i < this->num_philos)
	{
		pthread_join(this->philos[i].tid, NULL);
		pthread_mutex_destroy(&this->forks[i]);
		i++;
	}
	pthread_join(this->death_tid, NULL);
}

int	main(int argc, char **argv)
{
	t_this	*this;

	if (input_error_checking(argc, argv))
		return (1);
	this = malloc(sizeof(t_this));
	this->num_philos = ft_atoi(argv[1]);
	this->philos = malloc(sizeof(t_philo) * this->num_philos);
	this->forks = malloc(sizeof(pthread_mutex_t) * this->num_philos);
	init_and_start_philos(argv, this);
	pthread_create(&this->death_tid, NULL, death_check_thread, (void *)this);
	block_threads(this);
	free(this->forks);
	free(this->philos);
	free(this);
}
