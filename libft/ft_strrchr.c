/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:36:43 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/18 12:52:19 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	l;
	int		i;

	i = ft_strlen(s);
	l = (char)c;
	str = (char *)s;
	if (l == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == l)
			return (&str[i]);
		i--;
	}
	return (0);
}
