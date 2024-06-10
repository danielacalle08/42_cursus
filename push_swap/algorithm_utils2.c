/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:16:00 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/26 17:19:18 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	determine_cost(t_pile *a, t_pile *b, int size_a, int size_b)
{
	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	write(1, "COST\n", 5);
	while (a)
	{
		printf("UPDOWN = %i\nTARGET UPDOWN = %p\n", a->updown, a->target);
		if (a->updown == 1 && a->target->updown == -1)
			a->cost = a->index + (size_b - a->target->index);
		else if (a->updown == 1 && a->target->updown == 1)
		{
			if (a->index >= a->target->index)
				a->cost = a->index;
			else
				a->cost = a->target->index;
		}
		else if (a->updown == -1 && a->target->updown == 1)
			a->cost = a->target->index + (size_a - a->index);
		else if (a->updown == -1 && a->target->updown == -1)
		{
			if ((size_a - a->index) >= (size_b - a->target->index))
				a->cost = (size_a - a->index);
			else
				a->cost = (size_b - a->target->index);
		}
		a = a->next;
	}
}

void	find_cheapest(t_pile *a)
{
	int		cheapest;
	t_pile	*cheapest_node;

	cheapest = INT_MAX;
	cheapest_node = NULL;
	while (a != NULL)
	{
		if (a->cost == 0)
		{
			a->cheap = 1;
			return ;
		}
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	if (cheapest_node != NULL)
	{
		cheapest_node->cheap = 1;
	}
}