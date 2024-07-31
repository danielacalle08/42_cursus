/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:57 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/07/31 20:12:45 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int				i;
	t_data			data;
	t_philo			philo[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	i = 0;
	if (check_input(av) == 1)
		return (printf("Arguments can't be negative\n"), 1);
	else if (check_input(av) == 2)
		return (printf("Invalid character in your argument\n"), 2);
	else if (ac < 5 || ac > 6)
		return (printf("You must put 4 or 5 arguments!\n"), 3);
	else if (ft_atoi(av[1]) > MAX_PHILO)
		return (printf("Too many philosophers"), 4);
	init_data(av, &data);
	init_philosophers(av[1], philo, &data, forks);
	create_threads(philo, -1);
	pthread_mutex_destroy(&(&data)->lock_dead);
	pthread_mutex_destroy(&(&data)->lock_write);
	pthread_mutex_destroy(&(&data)->lock_start);
	while (i < (&data)->nbr_philos)
		pthread_mutex_destroy(&forks[i++]);
	return (0);
}
