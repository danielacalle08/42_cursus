/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:33:37 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/06 15:49:57 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}	
	return (str);
}

// char	ft_test(unsigned int i, char c)
// {
// 	char	s;

// 	s = c + i;
// 	return (s);
// }

// int	main(void)
// {
// 	char	*s;

// 	s = "daniela";
// 	printf("%s", ft_strmapi(s, ft_test));
// }
