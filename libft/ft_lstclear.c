/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:02:08 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/03 18:13:57 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s;
	t_list	*tmp;

	s = *lst;
	while (s)
	{
		tmp = s->next;
		del(s->content);
		free(s);
		s = tmp;
	}
	*lst = NULL;
}
