/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:44:28 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/03/19 16:00:29 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define ERROR_MESSAGE "ERROR \nPara ejecutar el proyecto debes utilizar:\n\
- './fractol mandelbrot' para el conjunto de Mandelbrot.\n\
- './fractol julia [coordenada_X] [coordenada_Y]' para el conjunto de Julia, \
con las coordenadas especificadas.\n"
# define WIDTH 864
# define HEIGHT 684
# define CLOSE_X 17
# define ESCAPE 53
# define LEFT 123
# define RIGHT 124
# define PLUS 30
# define MINUS 44
# define PLUS_NUM 69
# define MINUS_NUM 78
# define UP 126
# define DOWN 125
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ON_MOUSE_MOVE 6
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED   0xFF0000
# define GREEN 0x00FF00
# define BLUE  0x0000FF
# define YELLOW 0xFFFF00   // Rojo y verde combinados
# define MAGENTA 0xFF00FF  // Rojo y azul combinados
# define CYAN 0x00FFFF     // Verde y azul combinados
# define PINK      0xFF1493   // Rosa brillante
# define ORANGE    0xFFA500   // Naranja intenso
# define PURPLE    0x800080   // Púrpura oscuro
# define TEAL      0x008080   // Verde azulado
# define GOLDENROD 0xDAA520   // Dorado intenso
# define LIME      0x00FF00   // Lima brillante
# define ELECTRIC_BLUE  0x7DF9FF // Azul eléctrico
# define VIOLET_RED     0xFF3E96 // Rojo violeta
# define AQUAMARINE     0x7FFFD4 // Aguamarina
# define RASPBERRY_PINK 0xE30B5D // Rosa frambuesa
# define COSMIC_PURPLE  0x7851A9 // Púrpura cósmico

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
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

// **String utils**
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atoi_double(char *str);
int			ft_strlen(const char *s);

// **Init**
void		fractal_init(t_fractal *fractal);

// **Render**
void		fractal_render(t_fractal *fractal);

// **Math utils**
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		scale(double unscaled, double old_max, \
double new_min, double new_max);

// **Events**
int			close_window(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			mouse_handler(int btn, int x, int y, t_fractal *fractal);
int			mouse_move(int x, int y, t_fractal *fractal);

#endif