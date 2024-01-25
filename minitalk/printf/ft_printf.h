/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:43:10 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/11/01 16:56:12 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

unsigned int	ft_puthex_may(size_t num, char c);
unsigned int	ft_puthex_min(size_t num, char c);
size_t			ft_pointer(size_t num, char c);
int				ft_printf(char const *str, ...);
int				ft_putchar(char c);
int				ft_putnbr(int nb);
int				ft_putstr(char *str);
int				ft_putunbr(unsigned int n);

#endif
