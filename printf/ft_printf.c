/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:40:23 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/20 21:33:57 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_format(va_list list, char str, int len)
{
	if (str == '%')
		len += ft_putchar('%');
	if (str == 'c')
		len += ft_putchar(va_arg(list, int));
	if (str == 's')
		len += ft_putstr(va_arg(list, char *));
	if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(list, int));
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		len;

	len = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
			len = ft_get_format(list, *(++str), len);
		else
		{
			ft_putchar(*str);
			len++;
		}
		str++;
	}
	va_end(list);
	return (len);
}
