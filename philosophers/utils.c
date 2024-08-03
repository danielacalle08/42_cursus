/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:49 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/08/03 17:01:39 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_info(const char *color_code, char *str, t_philo *philosopher)
{
	size_t	time;

	pthread_mutex_lock(&philosopher->data->lock_write);
	time = get_current_time() - philosopher->start_time;
	if (!check_dead(philosopher))
		printf("%s%zu %d %s\n", color_code, time, philosopher->id, str);
	pthread_mutex_unlock(&philosopher->data->lock_write);
}

void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

int	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (3);
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!av[i][j] || av[i][j] == '-')
				return (1);
			if (av[i][j] < '0' || av[i][j] > '9')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}
