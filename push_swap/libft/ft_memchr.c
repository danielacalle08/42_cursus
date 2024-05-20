/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:18:18 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/05 17:27:57 by dcalle-m         ###   ########.fr       */
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
// int	main(void)
// {
// 	char	str[] = "Hola mundo";
// 	char	*result = (char *)ft_memchr(str, 'm', 7);

// 	if (result != NULL)
// 		printf("Encontrado: %c\n", *result);
// 	else
// 		printf("No encontrado.\n");
// 	return (0);
// }
