/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:16:00 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/26 17:19:18 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_upward_rotation(int index_a, int index_b, t_pile **a, t_pile **b)
{
	if (index_a >= index_b)
	{
		while (index_b -- > 0 && index_a --)
			rr(a, b);
		while (index_a -- > 0)
			ra(a);
		pb(b, a);
	}
	else if (index_a < index_b)
	{
		while (index_a -- > 0 && index_b --)
			rr(a, b);
		while (index_b -- > 0)
			rb(b);
		pb(b, a);
	}
}

void	handle_downward_rotation(int index_a, int index_b, t_pile **a, t_pile **b)
{
	if (index_a >= index_b)
	{
		while (index_b -- > 0 && index_a --)
			rrr(a, b);
		while (index_a -- > 0)
			rra(a);
		pb(b, a);
	}
	else if (index_a < index_b)
	{
		while (index_a -- > 0 && index_b --)
			rrr(a, b);
		while (index_b -- > 0)
			rrb(b);
		pb(b, a);
	}
}

void	handle_rotation_case(t_pile **a, t_pile **b, t_pile *cheapest)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;

	index_a = cheapest->index;
	index_b = cheapest->target->index;
	aux_a = (ft_stack_size(*a) - cheapest->index);
	aux_b = (ft_stack_size(*b) - cheapest->target->index);
	if (cheapest->updown == 1)
	{
		handle_upward_rotation(index_a, index_b, a, b);
	}
	else if (cheapest->updown == -1)
	{
		handle_downward_rotation(aux_a, aux_b, a, b);
	}
}

void	update_piles(t_pile **a, t_pile **b)
{
	update_index_updown(*a);
	update_index_updown(*b);
	update_target(*a, *b);
	determine_cost(*a, *b, 0, 0);
	write(1, "UPDATE\n", 7);
	find_cheapest(*a);
}

void	move_smallest_to_top(t_pile **a)
{
	t_pile	*min;

	min = find_min(*a, INT_MIN);
	while ((*a)->value != min->value)
	{
		if (min->updown == 1)
			ra(a);
		else
			rra(a);
	}
}