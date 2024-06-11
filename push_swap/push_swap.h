/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:30:01 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/06/11 21:00:51 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_pile
{
	int				value;
	int				index;
	int				updown;
	int				cost;
	int				cheap;
	struct s_pile	*next;	
	struct s_pile	*prev;
	struct s_pile	*target;
}				t_pile;

int			ft_stack_size(t_pile *stack);
t_pile		*ft_stack_last(t_pile *stack);
int			ft_isdigit(int str);
int			ft_atoi_long(const char *str);
int			ft_repeated_nbr(t_pile *stack, int nbr);
void		ft_free_pile(t_pile **stack);
int			ft_stack_init(t_pile **stack, char **argv);
void		ft_print_stack(t_pile *stack);
void		ft_reverse_rotate_pile(t_pile **pile);
void		rra(t_pile **a);
void		rrb(t_pile **b);
void		rrr(t_pile **a, t_pile **b);
void		ft_swap_nbr(t_pile **stack);
void		sa(t_pile **stack);
void		sb(t_pile **stack);
void		ss(t_pile **stack);
void		ft_push_pile(t_pile **src_pile, t_pile **dst_pile);
void		pa(t_pile **a, t_pile **b);
void		pb(t_pile **a, t_pile **b);
void		ft_rotate_pile(t_pile **pile);
void		ra(t_pile **a);
void		rb(t_pile **b);
int			ft_stack_sorted(t_pile *stack);
void		rr(t_pile **a, t_pile **b);
void		update_index_updown(t_pile *lst);
void		update_target(t_pile *a, t_pile *b);
void		handle_upward_rotation(int index_a, int index_b, \
			t_pile **a, t_pile **b);
void		handle_downward_rotation(int index_a, int index_b, \
			t_pile **a, t_pile **b);
void		handle_rotation_case(t_pile **a, t_pile **b, t_pile *cheapest);
void		update_piles(t_pile **a, t_pile **b);
void		move_smallest_to_top(t_pile **a);
void		handle_opposite_rotation(t_pile **a, t_pile **b, t_pile *cheapest);
t_pile		*get_cheapest(t_pile *lst);
void		return_b_to_a(t_pile **a, t_pile **b);
t_pile		*find_max(t_pile *lst, long max_nbr);
void		determine_cost(t_pile *a, t_pile *b, int size_a, int size_b);
void		sort_pile(t_pile **a, t_pile **b);
void		sort_and_return(t_pile **a, t_pile **b);
void		sorting_five(t_pile **a, t_pile **b, t_pile *min1, t_pile *min2);
void		sorting_three(t_pile **lst);
void		start_sorting(t_pile **a, t_pile **b);
void		find_cheapest(t_pile *a);
void		determine_cost(t_pile *a, t_pile *b, int size_a, int size_b);
t_pile		*find_min(t_pile *lst, long min_nbr);
int			ft_isvalid(int c);
int			check_args(char **argv, int i, int j);

#endif