/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:00:11 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/06/12 16:44:00 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (0);
	return (1);
}

int	check_args(char **argv, int i, int j)
{
	while (argv[i] != NULL)
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (!ft_isdigit(argv[i][++j]))
					return (0);
			}
			else if (ft_isdigit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if ((!ft_isdigit(argv[i][j])) && argv[i][j] != ' ')
					return (0);
			}
			if (!ft_isvalid(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		printf("Error\n");
		return (0);
	}
	if (check_args(argv, 1, 0) == 0 || argv[1][0] == '\0' || argv[1][0] == ' ')
	{
		printf("Error\n");
		return (1);
	}
	if (2 == argc && ft_strlen(argv[1]) > 2)
		ft_stack_init(&a, ft_split(argv[1], ' '));
	else if (2 == argc && ft_strlen(argv[1]) == 1)
		return (1);
	else
		ft_stack_init(&a, argv + 1);
	if (ft_stack_sorted(a) == 1)
		start_sorting(&a, &b);
	ft_free_pile(&a);
	return (0);
}
