/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:23:05 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/11/01 17:27:47 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pointer(size_t num, char c)
{
	int	len;

	len = 0;
	if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthex_min(num, 'x');
	}
	return (len);
}
