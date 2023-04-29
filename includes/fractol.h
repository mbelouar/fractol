#ifndef     FRACTOL_H
# define    FRACTOL_H

# include <math.h>
# include "mlx.h"

# define WIDTH		1200
# define HEIGHT		800
# define TITLE		"Fractol"

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
    double      c_re;
    double      c_im;
    double      z_re;
    double      z_im;
	double		mouse_x;
	double		mouse_y;
    int         iter;
	int			max_iter;
    rgb_colors  color;
}				t_fractal;


void    ft_menu_display(void);
void    ft_print_usage(void);
void	ft_putstr(char *s);
int     ft_strlen(char *str);
int		ft_check_choice(*name, t_fractal *fract);
void	ft_init_fractal(t_fractal fract);
void	ft_init_image(t_fractal *fract);
void    set_complex_pixel_and_draw(t_fractal *fract);
int     ft_algo_of_each_fract(t_fractal *fract);
int     ft_mandelbrot(t_fractal *fract);
int     ft_julia(t_fractal *fract);

#endif