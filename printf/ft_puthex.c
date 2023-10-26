/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:58:39 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/26 15:22:50 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t num, char c)
{
	int		len;
	char	*base;

	len = 0;
	if (c == 'x')
	{
		base = "0123456789abcdef";
		if (num <= 15)
			len += ft_putchar(base[num]);
		if (num >= 16)
		{
			len += ft_puthex((num / 16), c);
			len += ft_putchar(base[num % 16]);
		}
		return (len);
	}
	base = "0123456789ABCDEF";
	if (num <= 15)
		len += ft_putchar(base[num]);
	if (num >= 16)
	{
		len += ft_puthex((num / 16), c);
		len += ft_putchar(base[num % 16]);
	}
	return (len);
}
