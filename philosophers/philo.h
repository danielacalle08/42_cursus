/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:53 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/07/31 20:06:56 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO 800

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meals;
	size_t				last_meal;
	size_t				start_time;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct s_data		*data;
}				t_philo;

typedef struct s_data
{
	int				nbr_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nbr_meals;
	t_philo			*philosopher;
	int				dead_flag;
	int				start_flag;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_start;
	pthread_mutex_t	lock_write;
}				t_data;

int		ft_atoi(const char *str);
int		check_input(char **av);
void	init_forks(pthread_mutex_t *forks, int n_philos);
void	init_philosophers(char *av, \
t_philo *philo, t_data *data, pthread_mutex_t *fork);
void	init_data(char **av, t_data *data);
void	set_start(t_philo *philosopher);
void	set_dead(t_philo *philosopher);
int		check_dead(t_philo *philosopher);
size_t	get_current_time(void);
void	print_info(char *str, t_philo *philosopher);
void	ft_usleep(size_t milliseconds);
void	eat_routine(t_philo *philosopher);
void	*routine(void *arg);
void	create_threads(t_philo *p, int i);

#endif