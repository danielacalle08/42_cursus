/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:15:47 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/04 17:51:23 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;
	void	*content;

	p = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		s = ft_lstnew(content);
		if (!s)
		{
			del(content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, s);
		lst = lst->next;
	}
	return (p);
}
