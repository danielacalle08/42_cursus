/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:15:19 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/07/31 18:21:29 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->data->lock_start);
	philosopher->data->start_flag = 1;
	pthread_mutex_unlock(&philosopher->data->lock_start);
}

void	set_dead(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->data->lock_dead);
	philosopher->data->dead_flag = 1;
	pthread_mutex_unlock(&philosopher->data->lock_dead);
}

int	check_dead(t_philo *philosopher)
{
	int	dead_flag;

	pthread_mutex_lock(&philosopher->data->lock_dead);
	dead_flag = philosopher->data->dead_flag;
	pthread_mutex_unlock(&philosopher->data->lock_dead);
	return (dead_flag);
}
