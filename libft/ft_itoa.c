/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:32:48 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/26 17:25:41 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i = 1;
	while (c != 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		size2;
	long	num;

	num = n;
	size = ft_count(num);
	size2 = size;
	str = ft_calloc((size2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num = num * (-1);
		str[0] = '-';
	}
	while ((size > 0 && str[0] != '-') || ((str[0] == '-') && size > 1))
	{
		str[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	str[size2] = '\0';
	return (str);
}
