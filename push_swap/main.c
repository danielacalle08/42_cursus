/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:00:11 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 16:53:04 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_parse(char *argv, t_stack **a)
{
	char	**temp;

	temp = ft_split(argv, 32);
	if (ft_repeated_nbr(temp, 0) == 0)
	{
		ft_free_pile(temp);
	}
	ft_stack_init(temp, a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (check_args(argv, 1, 0) == 0 || argv[1][0] == '\0' || argv[1][0] == ' ')
			ft_error();
		else
			quoted_parse(argv[1], &a);
	}
	if (argc > 2)
	{
		if (check_args(argv, 1, 0) == 0 || check_duplicates(argv, 1) == 0)
			ft_error();
		else
			stack_init(argv, argc, &a, 1);
	}
	sort_start(&a, &b);
	free_stack(&b);
	free_stack(&a);
	return (0);
}