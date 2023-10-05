/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:14:45 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/05 17:10:36 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	int	i;
// 	int	x;
// 	int	s;

// 	i = '*';
// 	x = '1';
// 	s = 'd';
// 	printf("%d\n", ft_isalnum(i));
// 	printf("%d\n", ft_isalnum(x));
// 	printf("%d\n", ft_isalnum(s));
// }
