/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:50:50 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/07/31 18:15:00 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(pthread_mutex_t *forks, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philosophers(char *av,
						t_philo *philo, t_data *data, pthread_mutex_t *fork)
{
	int	i;
	int	n_philos;

	n_philos = ft_atoi(av);
	init_forks(fork, n_philos);
	i = 0;
	while (i < n_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].start_time = get_current_time();
		philo[i].last_meal = get_current_time();
		philo[i].data = data;
		philo[i].right_fork = &fork[i];
		if (i == n_philos - 1)
			philo[i].left_fork = &fork[0];
		else
			philo[i].left_fork = &fork[i + 1];
		i++;
	}
	data->philosopher = philo;
}

void	init_data(char **av, t_data *data)
{
	data->nbr_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nbr_meals = ft_atoi(av[5]);
	else
		data->nbr_meals = 0;
	data->dead_flag = 0;
	data->start_flag = 0;
	pthread_mutex_init(&data->lock_dead, NULL);
	pthread_mutex_init(&data->lock_write, NULL);
	pthread_mutex_init(&data->lock_start, NULL);
}
