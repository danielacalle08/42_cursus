/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:25:49 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/07/31 20:14:57 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_routine(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	print_info("has taken a fork", philosopher);
	if (philosopher->left_fork == philosopher->right_fork)
	{
		pthread_mutex_unlock(philosopher->right_fork);
		print_info("died", philosopher);
		set_dead(philosopher);
		return ;
	}
	pthread_mutex_lock(philosopher->left_fork);
	print_info("has taken a fork", philosopher);
	philosopher->last_meal = get_current_time();
	print_info("is eating", philosopher);
	ft_usleep(philosopher->data->time_to_eat);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->start_flag)
		ft_usleep(10);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	while (!check_dead(philo))
	{
		eat_routine(philo);
		if (!philo->data->nbr_meals || (philo->meals < philo->data->nbr_meals))
			philo->meals++;
		else
			break ;
		print_info("is sleeping", philo);
		ft_usleep(philo->data->time_to_sleep);
		print_info("is thinking", philo);
	}
	return (arg);
}

void	create_threads(t_philo *p, int i)
{
	while (++i < p->data->nbr_philos)
	{
		if (pthread_create(&(p[i].thread), NULL, &routine, &p[i]))
			printf("Failed to create thread");
	}
	set_start(p);
	while (!check_dead(p) && (!p->data->nbr_meals || \
							p->meals < p->data->nbr_meals))
	{
		i = -1;
		while (++i < p->data->nbr_philos)
		{
			if ((get_current_time() - p[i].last_meal > p->data->time_to_die))
			{
				print_info("died", &p[i]);
				set_dead(p);
			}
		}
		i = -1;
		while (++i < p->data->nbr_philos)
		{
			if (pthread_join(p[i]. thread, NULL) != 0)
				printf("Failed to join thread");
		}
	}
}
