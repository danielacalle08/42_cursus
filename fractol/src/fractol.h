/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:44:28 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/02/27 20:51:40 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define ERROR_MESSAGE "Error: Please enter\n'./fractol mandelbrot' or\n'./fractol julia <value1> <value2>'\n"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_img
{
	void	*img_ptr;
	void	*pixel_ptr;
	int		bits_per_pixels;
	int		endian;
	int		size_line;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_fractal;

// **String utils**
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// **Init**
void	fractal_init(t_fractal *fractal);

#endif