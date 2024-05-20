/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:30:01 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/26 18:25:06 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;	
	struct s_list	*prev;
}				t_list;

int			ft_stack_size(t_list *stack);
t_list		*ft_stack_last(t_list *stack);
int			ft_isdigit(int str);
int			ft_atoi_long(const char *str);
int			ft_repeated_nbr(t_list *stack, int nbr);
void		ft_free(t_list **stack);
int			ft_stack_init(t_list **stack, char **argv);
void		ft_print_stack(t_list *stack);
void		ft_swap_nbr(t_list **stack);

#endif