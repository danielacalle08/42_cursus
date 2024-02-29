/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:53:38 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:10 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bits_per_pixels / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	draw_pixel(int x, int y, t_fractal *fractal)
{
	int			color;
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(x, WIDTH, -2, 2);
	c.y = scale(y, HEIGHT, 2, -2);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale(i, fractal->iterations, WHITE, BLUE);
			my_pixel_put(x, y, color, &fractal->img);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, VIOLET_RED, &fractal->img);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
