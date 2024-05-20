/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:35:57 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/06 16:18:00 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}

void	ft_test2(unsigned int i, char *s)
{
	*s = *s + i;
}

// int	main(void)
// {
// 	char	s[50] = "daniela";

// 	ft_striteri(s, ft_test2);
// 	printf("%s", s);
// }
