/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:53:38 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/12 18:07:02 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, int color, t_img *img)
{
	int	position;

	position = (y * img->size_line) + (x * (img->bits_per_pixels / 8));
	*(unsigned int *)(img->pixel_ptr + position) = color;
}

static void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	draw_image(int x, int y, t_fractal *fractal)
{
	int			color;
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = (scale(x, WIDTH, -2, 2) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, HEIGHT, -2, 2) * fractal->zoom) + fractal->shift_y;
	mandelbrot_or_julia(&z, &c, fractal);
	while (++i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale(i, fractal->iterations, GOLDENROD, AQUAMARINE);
			my_pixel_put(x, y, color, &fractal->img);
			return ;
		}
	}
	my_pixel_put(x, y, LIME, &fractal->img);
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
			draw_image(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
