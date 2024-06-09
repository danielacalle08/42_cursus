/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:49 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:02 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_repeated_nbr(t_pile *stack, int nbr)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_stack_sorted(t_pile *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_free_pile_pile(t_pile **stack)
{
	t_pile	*tmp;
	t_pile	*node;

	if (stack == NULL)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}
