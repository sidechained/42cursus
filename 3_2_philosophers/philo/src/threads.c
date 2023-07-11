/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/07/01 21:57:54 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	lock_in_order(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		if (philo->alive)
			print(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_fork);
		if (philo->alive)
			print(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (philo->alive)
			print(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->left_fork);
		if (philo->alive)
			print(philo, "has taken a fork\n");
	}
	if (philo->alive)
		print(philo, "is eating\n");
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
	print(philo, "is thinking\n");
	while (philo->alive)
	{
		lock_in_order(philo);
		philo->time_last_eaten = ts();
		wait(philo->info->time_to_eat);
		unlock_in_order(philo);
		if (philo->alive == false)
			break ;
		philo->num_times_eaten++;
		if (philo->info->num_times_must_eat != 0
			&& philo->num_times_eaten >= philo->info->num_times_must_eat)
		{
			philo->finished_eating = true;
			break ;
		}
		print(philo, "is sleeping\n");
		wait(philo->info->time_to_sleep);
	}
	return (NULL);
}

void	*monitoring_thread(void *void_info)
{
	t_info	*info;
	int		i;

	info = ((t_info *)void_info);
	while (1)
	{
		i = 0;
		while (i < info->num_philos)
		{
			if (info->philos[i].finished_eating)
				return (NULL);
			i++;
		}
		usleep(1);
		if (death_checker(info))
			return (NULL);
	}
}

int	death_checker(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (ts() > info->philos[i].time_last_eaten
			+ info->time_to_die)
		{
			print(&info->philos[i], "died\n");
			if (info->num_philos == 1)
				pthread_mutex_unlock(info->philos[i].left_fork);
			i = 0;
			while (i < info->num_philos)
			{
				info->philos[i].alive = false;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
