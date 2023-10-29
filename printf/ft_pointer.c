/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielacallemeneses <danielacallemenese    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:23:05 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/29 20:47:55 by danielacall      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(size_t num, char c)
{
	int	len;

	len = 0;
	if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthex(num, 'x');
	}
	return (len);
}
