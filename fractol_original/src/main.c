/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:42 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/19 16:13:08 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (ft_strncmp(argv[1], "mandelbrot", \
	ft_strlen(argv[1])) == 0))
		|| (argc == 4 && (ft_strncmp(argv[1], \
		"julia", ft_strlen(argv[1])) == 0)))
	{
		fractal.name = argv[1];
		if (ft_strncmp(fractal.name, "julia", \
		(ft_strlen(argv[1]))) == 0)
		{
			fractal.julia_x = atoi_double(argv[2]);
			fractal.julia_y = atoi_double(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
