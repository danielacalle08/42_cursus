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
	if (argc == 1)
		return (0);
	t_pile	*stack;
	ft_stack_init(&stack, argv + 1);
	printf("antes\n");
	ft_print_stack(stack);
	ft_swap_nbr(&stack);
	printf("despues\n");
	ft_print_stack(stack);
}
