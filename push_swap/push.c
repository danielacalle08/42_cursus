/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:29:25 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 18:34:41 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_pile(t_pile **src_pile, t_pile **dst_pile)
{
    t_pile  *src_element;
    t_pile  *dst_element;

    if (*src_pile == NULL)
        return ;
    src_element = *src_pile;
    dst_element = *dst_pile;
    *src_pile = src_element->next;
    if (src_element->next)
        src_element->next->prev = NULL;
    src_element->next = dst_element;
    src_element->prev = NULL;
    if (dst_element)
        dst_element->prev = src_element;
    *dst_pile = src_element;
}

void    pa(t_pile **a, t_pile **b)
{
    ft_push_pile(b, a);
    printf("pa\n");
}

void    pb(t_pile **a, t_pile **b)
{
    ft_push_pile(a, b);
    printf("pb\n");
    int idx = -1;
    // IMPRIMIR STACK A
    /*
    while ()
    {
        printf("");
    }
    

    */

}