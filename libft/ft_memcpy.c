/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:43:28 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/26 15:21:57 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	if (ptr1 == 0 && ptr2 == 0)
		return (0);
	if (src == ptr1 || !n)
		return (ptr1);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str[40] = "hola";
// 	char	dst[40] = "adios";

// 	printf("antes %s\n", dst);
// 	ft_memcpy(dst, str, 3);
// 	printf("luego %s\n", dst);
// 	return (0);
// }
