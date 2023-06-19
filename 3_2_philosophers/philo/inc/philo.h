/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/19 10:43:15 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include "libft.h"

typedef struct s_philo
{
	int				index;
	pthread_t		tid;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	int				num_times_eaten;	
	bool			alive;
	bool			finished_eating;
	long long		start;
	long long		time_last_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;	
}	t_philo;

typedef struct s_this
{
	int				num_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		monitor_tid;
}	t_this;

int			input_error_checking(int argc, char **argv);
long long	ts(void);
void		wait(long long time);
void		*monitoring_thread(void *this);

#endif