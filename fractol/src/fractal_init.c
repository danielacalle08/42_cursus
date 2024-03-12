/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:03:31 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/12 17:04:22 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 60;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1.0;
}

static void	event_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, CLOSE_X, 0, close_window, fractal);
}

static void	malloc_error(void)
{
	perror("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH,
			HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixels,
			&fractal->img.size_line,
			&fractal->img.endian);
	data_init(fractal);
	event_init(fractal);
}
