/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:29:20 by gbooth            #+#    #+#             */
/*   Updated: 2023/07/12 08:31:13 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				num_times_eaten;
	bool			alive;
	bool			finished_eating;
	long long		time_last_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	long long		start;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;	
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_t		monitor_tid;
}	t_info;

void		print(t_philo *philo, char *str);
int			input_error_checking(int argc, char **argv);
long long	ts(void);
void		wait(long long time);
int			death_checker(t_info *info);
void		*philo_thread(void *void_philo);
void		*monitoring_thread(void *void_info);

#endif