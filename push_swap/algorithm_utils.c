/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:16:00 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/26 17:19:18 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_opposite_rotation(t_pile **a, t_pile **b, t_pile *cheapest)
{
	int	index_a;
	int	index_b;
	int	aux_a;
	int	aux_b;

	index_a = cheapest->index;
	index_b = cheapest->target->index;
	aux_a = (ft_stack_size(*a) - cheapest->index);
	aux_b = (ft_stack_size(*b) - cheapest->target->index);
	if (cheapest->updown == 1 && cheapest->target->updown == -1)
	{
		while (index_a -- > 0)
			ra(a);
		while (aux_b -- > 0)
			rrb(b);
		pb(b, a);
	}
	else if (cheapest->updown == -1 && cheapest->target->updown == 1)
	{
		while (aux_a -- > 0)
			rra(a);
		while (index_b -- > 0)
			rb(b);
		pb(b, a);
	}
}

t_pile	*get_cheapest(t_pile *lst)
{
	while (lst)
	{
		if (lst->cheap == 1)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	return_b_to_a(t_pile **a, t_pile **b)
{
	while (*b)
	{
		pa(a, b);
	}
}

t_pile	*find_max(t_pile *lst, long max_nbr)
{
	long	max;
	t_pile	*max_node;

	if (!lst)
		return (NULL);
	max = INT_MIN;
	max_node = NULL;
	while (lst)
	{
		if (lst->value == INT_MAX)
			return (lst);
		if (lst->value > max && lst->value < max_nbr)
		{
			max = lst->value;
            max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_pile	*find_min(t_pile *lst, long min_nbr)
{
	long	min;
	t_pile	*min_node;

	if (!lst)
		return (NULL);
	min = INT_MAX;
	min_node = NULL;
	while (lst)
	{
		if (lst->value == INT_MIN)
			return (lst);
		if (lst->value < min && lst->value > min_nbr)
		{
			min = lst->value;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}