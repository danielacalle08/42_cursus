/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:19:23 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/12 18:15:24 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && str1[i] == str2[i] && n - 1 > i)
		i++;
	return ((str1[i] - str2[i]));
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

int	atoi_double(char *str)
{
	long	integer;
	double	decimal;
	double	exp;
	int		sign;

	integer = 0;
	decimal = 0;
	sign = 1;
	exp = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
		if (*str == '-')
			sign = -1;
	while (*str != '.' && *str)
		integer = (integer * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		exp /= 10;
		decimal += (*str++ - '0') * exp;
	}
	return ((integer + decimal) * sign);
}
