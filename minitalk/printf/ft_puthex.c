/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:58:39 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/11/01 16:53:21 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthex_min(size_t num, char c)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (c == 'x')
	{
		if (num <= 15)
		{
			len += ft_putchar(base[num]);
			return (len);
		}
		if (num >= 16)
		{
			len += ft_puthex_min((num / 16), c);
			len += ft_putchar(base[num % 16]);
			return (len);
		}
		return (0);
	}
	return (len);
}

unsigned int	ft_puthex_may(size_t num, char c)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789ABCDEF";
	if (c == 'X')
	{
		if (num <= 15)
		{
			len += ft_putchar(base[num]);
			return (len);
		}
		if (num >= 16)
		{
			len += ft_puthex_may((num / 16), c);
			len += ft_putchar(base[num % 16]);
			return (len);
		}
		return (0);
	}
	return (len);
}
