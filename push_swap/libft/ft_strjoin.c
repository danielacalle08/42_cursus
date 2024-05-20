/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:17:17 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/06 15:34:55 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*res2;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	res2 = res;
	if (!res)
	{
		return (NULL);
	}
	while (*s1 != '\0')
	{
		*res2++ = *s1++;
	}
	while (*s2 != '\0')
	{
		*res2++ = *s2++;
	}
	*res2 = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*r;

// 	s = "daniela";
// 	r = "calle";
// 	printf("%s", ft_strjoin(s, r));
// 	return (0);
// }
