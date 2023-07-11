/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/07/01 21:46:25 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	init_and_start_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		info->philos[i].index = i;
		info->philos[i].num_times_eaten = 0;
		info->philos[i].time_last_eaten = info->start;
		info->philos[i].alive = true;
		info->philos[i].finished_eating = false;
		info->philos[i].left_fork = &info->forks[i];
		info->philos[i].right_fork = &info->forks[(i + 1) % info->num_philos];
		info->philos[i].info = info;
		pthread_create(&info->philos[i].tid, NULL, philo_thread,
			(void *)&info->philos[i]);
		i++;
	}
}

void	init_info(t_info **info, char **argv)
{
	(*info)->num_philos = ft_atoi(argv[1]);
	(*info)->philos = malloc(sizeof(t_philo) * (*info)->num_philos);
	(*info)->forks = ft_calloc((*info)->num_philos, sizeof(pthread_mutex_t));
	(*info)->start = ts();
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		(*info)->num_times_must_eat = ft_atoi(argv[5]);
	else
		(*info)->num_times_must_eat = 0;
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	if (input_error_checking(argc, argv))
		return (-1);
	info = malloc(sizeof(t_info));
	init_info(&info, argv);
	pthread_mutex_init(&info->print, NULL);
	init_and_start_philos(info);
	pthread_create(&info->monitor_tid, NULL, monitoring_thread, (void *)info);
	pthread_join(info->monitor_tid, NULL);
	i = 0;
	while (i < info->num_philos)
	{
		pthread_join(info->philos[i].tid, NULL);
		i++;
	}
	free(info->forks);
	free(info->philos);
	free(info);
	return (0);
}
