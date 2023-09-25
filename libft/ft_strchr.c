/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:07:25 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/18 12:30:38 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	l = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == l)
			return (&str[i]);
		i++;
	}
	if (l == '\0')
		return (&str[i]);
	return (0);
}
