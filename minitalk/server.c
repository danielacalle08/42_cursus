/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:55:47 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/01/25 16:27:07 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive(int sig)
{
	static int	byte;
	static int	word_len;

	if (sig == SIGUSR1)
		byte |= (0x01 << word_len);
	word_len++;
	if (word_len == 8)
	{
		ft_printf("%c", byte);
		word_len = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error!");
		return (0);
	}
	ft_printf("El id del servidor es: %i \n", getpid());
	ft_printf("Esperando...\n");
	while (1)
	{
		signal(SIGUSR1, ft_receive);
		signal(SIGUSR2, ft_receive);
		pause();
	}
	return (0);
}
