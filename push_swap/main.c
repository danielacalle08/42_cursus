/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:00:11 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/26 18:25:47 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	ft_stack_init(&stack, argv + 1);
	printf("antes\n");
	ft_print_stack(stack);
	ft_swap_nbr(&stack);
	printf("despues\n");
	ft_print_stack(stack);
}
