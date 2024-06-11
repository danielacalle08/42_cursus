/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:58:47 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 18:17:27 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_pile(t_pile **pile)
{
	int		len;
	t_pile	*first;
	t_pile	*last;

	len = ft_stack_size(*pile);
	if (pile == NULL || *pile == NULL || len < 2)
		return ;
	first = *pile;
	last = ft_stack_last(*pile);
	last->next = first;
	*pile = (*pile)->next;
	(*pile)->prev = NULL;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_pile **a)
{
	ft_rotate_pile(a);
	printf("ra\n");
}

void	rb(t_pile **b)
{
	ft_rotate_pile(b);
	printf("rb\n");
}

void	rr(t_pile **a, t_pile **b)
{
	ft_rotate_pile(a);
	ft_rotate_pile(b);
	printf("rr\n");
}
