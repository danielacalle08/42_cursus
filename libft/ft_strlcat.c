/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:59:08 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/18 10:41:28 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	dest_len = j;
	src_len = ft_strlen(src);
	if (size == 0 || size <= dest_len)
	{
		return (src_len + size);
	}
	while (src[i] != '\0' && i < size - dest_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= dest_len)
	{
		return (src_len + dstsize);
	}
	while (src[i] != '\0' && i < dstsize - dest_len - 1)
	{
		dst[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dst[dest_len] = '\0';
	return (dest_len + src_len);
} */
