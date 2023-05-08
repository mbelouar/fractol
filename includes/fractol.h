/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:33:09 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/01 19:33:09 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FRACTOL_H
# define    FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH		1200
# define HEIGHT		1000
# define TITLE		"Fractol"

typedef struct s_complex	t_complex;

struct						s_complex
{
	double					re;
	double					im;
};

typedef struct	e_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef enum	e_name {
	MANDELBROT,
	JULIA
}				t_name;

typedef struct rgb {
    int r;
    int g;
    int b;
}               rgb_colors;


typedef struct	s_fractal {
	t_image		image;
	t_name		fractal;
	void		*mlx_ptr;
	void		*win_ptr;
	double		tmp;
    double      c_re;
    double      c_im;
    double      z_re;
    double      z_im;
	double 		scale;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
    int         iter;
	int			max_iter;
    rgb_colors  color;
}				t_fractal;

void    ft_menu_display(void);
void    ft_print_usage(void);
void	ft_putstr(char *s);
void	ft_init_fractal(t_fractal *fract);
void	ft_init_image(t_fractal *fract);
void 	plot_point(t_fractal *fract, int x, int y, int color);
int		ft_check_choice(char *name, t_fractal *fract);
int     ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int 	get_color(t_fractal *fract, int iter);
void    ft_mandelbrot(t_fractal *fract);
int 	calculate_mandelbrot(t_fractal *fract);
void    ft_julia(t_fractal *fract);
int 	calculate_julia(t_fractal *fract);
int		ft_zoom(int mouse, int x, int y, t_fractal *fract);
int		esc_handle(int keycode, t_fractal *fract);
int		ft_close(t_fractal *fract);
void    julia_init(t_fractal *fract, char **av);
double	ft_atoif(char *str);

#endif