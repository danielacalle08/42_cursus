/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:18:18 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/18 13:26:49 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	l;

	i = 0;
	str = (unsigned char *)s;
	l = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == l)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
