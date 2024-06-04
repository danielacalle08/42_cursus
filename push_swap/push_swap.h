/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:30:01 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/05/27 18:32:16 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;	
	struct s_pile	*prev;
}				t_pile;

int			ft_stack_size(t_pile *stack);
t_pile		*ft_stack_last(t_pile *stack);
int			ft_isdigit(int str);
int			ft_atoi_long(const char *str);
int			ft_repeated_nbr(t_pile *stack, int nbr);
void		ft_free(t_pile **stack);
int			ft_stack_init(t_pile **stack, char **argv);
void		ft_print_stack(t_pile *stack);
void	    ft_reverse_rotate_pile(t_pile **pile);
void		ft_swap_nbr(t_pile **stack);
void    	ft_push_pile(t_pile **src_pile, t_pile **dst_pile);
void		ft_rotate_pile(t_pile **pile);

#endif