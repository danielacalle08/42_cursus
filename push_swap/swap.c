/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:28:00 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:55 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_nbr(t_pile **stack)
{
	t_pile	*first;
	t_pile	*second;

	if (ft_stack_size(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	*stack = second;
	second->prev = NULL;
	first->next = second->next;
	second->next = first;
	first->prev = second;
}

void	sa(t_pile **stack)
{
	ft_swap_nbr(stack);
	printf("sa\n");
}

void	sb(t_pile **stack)
{
	ft_swap_nbr(stack);
	printf("sb\n");
}

void	ss(t_pile **stack)
{
	ft_swap_nbr(stack);
	printf("ss\n");
}
