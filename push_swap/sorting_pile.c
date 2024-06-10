/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:39:45 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/03 13:51:36 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile(t_pile **a, t_pile **b)
{
	int		len;
	t_pile	*cheapest;

	len = ft_stack_size(*a);
	while (len > 0)
	{
		printf("STACK A: %i\nSTACK B: %i\n", ft_stack_size(*a), ft_stack_size(*b));
		cheapest = get_cheapest(*a);
		if (cheapest != NULL)
		{
			if (cheapest->updown == cheapest->target->updown)
			{
				handle_rotation_case(a, b, cheapest);
			}
			else if (cheapest->updown != cheapest->target->updown)
			{
				handle_opposite_rotation(a, b, cheapest);
			}
		}
		update_piles(a, b);
		len = ft_stack_size(*a);
	}
}

void	sort_and_return(t_pile **a, t_pile **b)
{
	pb(a, b);
	pb(a, b);
	if ((*b) && (*b)->value < (*b)->next->value)
		sb(b);
	update_piles(a, b);
	sort_pile(a, b);
	return_b_to_a(a, b);
	move_smallest_to_top(a);
}

void	sorting_five(t_pile **a, t_pile **b, t_pile *min1, t_pile *min2)
{
	update_index_updown(*a);
	min1 = find_min(*a, INT_MIN);
	while (*a != min1 && min1->updown == 1)
		ra(a);
	while (*a != min1 && min1->updown == -1)
		rra(a);
	pb(b, a);
	update_index_updown(*a);
	min2 = find_min(*a, INT_MIN);
	while (*a != min2 && min2->updown == 1)
		ra(a);
	while (*a != min2 && min2->updown == -1)
		rra(a);
	pb(b, a);
	sorting_three(a);
	if ((*b) && (*b)->value > (*b)->next->value)
		pa(a, b);
	else
	{
		sb(b);
		pa(a, b);
	}
	pa(a, b);
}

void	sorting_three(t_pile **lst)
{
	if ((*lst)->value < (((*lst)->next)->next)->value
		&& ((*lst)->next)->value < (((*lst)->next)->next)->value)
		sa(lst);
	else if ((*lst)->value > (((*lst)->next)->next)->value
		&& (*lst)->value < ((*lst)->next)->value)
		rra(lst);
	else if ((*lst)->value > (((*lst)->next)->next)->value
		&& ((*lst)->next)->value < (((*lst)->next)->next)->value)
		ra(lst);
	else if ((*lst)->value < (((*lst)->next)->next)->value
		&& ((*lst)->next)->value > (((*lst)->next)->next)->value)
	{
		sa(lst);
		ra(lst);
	}
	else
	{
		ra(lst);
		sa(lst);
	}
}

void	start_sorting(t_pile **a, t_pile **b)
{
	if (ft_stack_size(*a) == 2)
		sa(a);
	else if (ft_stack_size(*a) == 3)
		sorting_three(a);
	else if (ft_stack_size(*a) == 5)
		sorting_five(a, b, 0, 0);
	else
		sort_and_return(a, b);
}