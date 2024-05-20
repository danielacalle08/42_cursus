/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:58:16 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/15 12:49:01 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	i = 0;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		while (n-- > 0)
		{
			dst1[n] = src1[n];
		}
	}
	else
	{
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst1);
}

// int	main(void)
// {
// 	char	src[20] = "1111";
// 	char	dst[10] = "12345678";

// 	printf("antes: %s\n", dst);
// 	ft_memmove(dst, src, 7);
// 	printf("después: %s\n", dst);
// }
