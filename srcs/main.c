#include "fractol.h"

int main(int ac, char **av)
{
	t_fractal	fract;

	ft_menu_display();
	if (ac != 2 || ft_check_choice(av[1], fract) == 0)
	{
		ft_print_usage();
		exit(1);
	}
	ft_init_fractal(&fract);
	set_complex_pixel_and_draw(&fract);
}


void	ft_init_fractal(t_fractal *fract)
{
	fract->mlx_ptr = mlx_init();
	if (!(fract->mlx_ptr))
		ft_putstr("Mlx initialization failed\n");
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, TITLE);
		ft_putstr("Window creation failed\n");
	ft_init_image(&fract);
}


void	ft_init_image(t_fractal *fract)
{
	fract->image.img = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT);
	if (!fract->image.img)
		ft_putstr("Image creation failed\n");
	fract->image.addr = mlx_get_data_addr(fract->image.img, 
					&fract->image.bits_per_pixel, 
					&fract->image.line_length, 
					&fract->image.endian);
}

int		ft_check_choice(*choice, t_fractal *fract)
{
	if (ft_strlen(av[1]) = 1)
	{
		if (av[1][0] == 'M')
			fract->fractal = MANDELBROT;
		else if (av[1][0] == 'J')
			fract->fractal = JULIA;
		else
			return (0);
		return (1);
	}
	else
		ft_print_usage();
}