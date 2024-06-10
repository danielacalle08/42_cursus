/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:00:11 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 16:53:04 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		printf("La cagaste perro\n");
		return (0);
	}
	else if (2 == argc)
		ft_stack_init(&a, ft_split(argv[1], ' '));
	else
		ft_stack_init(&a, argv + 1);
	len = ft_stack_size(a);
	if (ft_stack_sorted(a) == 1)
	{
		start_sorting(&a, &b);
	}
	ft_free_pile(&a);
}
