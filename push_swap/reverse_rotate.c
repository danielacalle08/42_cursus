/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:18:44 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 18:34:54 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_reverse_rotate_pile(t_pile **pile)
{
    int     len;
    t_pile  *first;
    t_pile  *last;

    len = ft_stack_size(*pile);
    if (*pile == NULL || pile == NULL || len < 2)
        return ;
    first = *pile;
    last = ft_stack_last(*pile);
    last->prev->next = NULL;
    last->next = first;
    last->prev = NULL;
    *pile = last;
    first->prev = last;
}

void    rra(t_pile **a)
{
    ft_reverse_rotate_pile(a);
    printf("rra\n");
}

void    rrb(t_pile **b)
{
    ft_reverse_rotate_pile(b);
    printf("rrb\n");
}

void    rrr(t_pile **a, t_pile **b)
{
    ft_reverse_rotate_pile(a);
    ft_reverse_rotate_pile(b);
    printf("rrr\n");
}