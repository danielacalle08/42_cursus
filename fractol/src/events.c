/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:44:21 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/12 17:26:25 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE)
		close_window(fractal);
	if (keycode == LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == PLUS || keycode == PLUS_NUM)
		fractal->iterations += 10;
	else if (keycode == MINUS || keycode == MINUS_NUM)
		fractal->iterations -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int btn, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (btn == ZOOM_IN)
		fractal->zoom *= 0.95;
	else if (btn == ZOOM_OUT)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
