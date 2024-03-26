/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:28:00 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/26 18:29:41 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_nbr(t_list **stack)
{
	t_list	*first;
	t_list	*second;

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

void	swap_a(t_list **stack)
{
	ft_swap_nbr(stack);
	printf("sa\n");
}

void	swap_b(t_list **stack)
{
	ft_swap_nbr(stack);
	printf("sb\n");
}

void	swap_ss(t_list **stack)
{
	ft_swap_nbr(stack);
	printf("ss\n");
}
