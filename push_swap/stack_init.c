/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:47:19 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:46 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_nbr(t_pile **stack, int n)
{
	t_pile	*new;
	t_pile	*last;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_pile));
	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_stack_last(*stack);
		last->next = new;
		new->prev = last;
	}
	new->value = n;
	new->next = NULL;
}

int	ft_stack_init(t_pile **stack, char **argv)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (argv[i])
	{
		n = ft_atoi_long(argv[i]);
		if ((ft_repeated_nbr(*stack, n) == 1) || n > INT_MAX || n < INT_MIN)
		{
			printf("Error\n");
			if (stack && *stack)
				ft_free(stack);
			return (1);
		}
		ft_add_nbr(stack, n);
		i++;
	}
	return (0);
}
