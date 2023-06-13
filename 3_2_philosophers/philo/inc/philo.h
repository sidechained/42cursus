/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/06/13 12:40:55 by gbooth           ###   ########.fr       */
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
# include <ft_printf.h>

typedef struct s_phil
{
	int				i;
	int				end_reached;
	int				n_phs;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	long long		start;
	long long		time_last_eaten;
	int				num_times_eaten;
	pthread_t		tid;
	pthread_t		diechk_tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_phil;

int			input_error_checking(int argc, char **argv);
long long	ts(void);
void		wait(long long time);
void		create_diechk_threads(t_phil *phs);
void		*start_diechk(void *void_phil);

#endif