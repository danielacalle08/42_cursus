/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:24 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:15 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_pile *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_pile	*ft_stack_last(t_pile *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_print_stack(t_pile *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	update_target(t_pile *a, t_pile *b)
{
	while (a)
	{
		a->target = find_max(b, a->value);
		if (a->target == NULL)
			a->target = find_max(b, INT_MAX);
		a = a->next;
	}
}

void	update_index_updown(t_pile *lst)
{
	int	i;
	int	half;
	int	size;

	size = ft_stack_size(lst);
	half = (size / 2);
	i = 0;
	while (lst)
	{
		lst->index = i;
		if (i > half)
			lst->updown = -1;
		else if (i == half)
		{
			if (size % 2 == 0)
				lst->updown = -1;
			else
				lst->updown = 1;
		}
		else if (i < half)
			lst->updown = 1;
		i++;
		lst = lst->next;
	}
}
