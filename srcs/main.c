/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:33:00 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/08 22:25:36 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fract;

	if (ft_check_choice(ac, av, &fract) == 0)
	{
		ft_menu_display();
		exit(1);
	}
	ft_init_fractal(&fract);
	if (fract.fractal == MANDELBROT)
		ft_mandelbrot(&fract);
	else if (fract.fractal == JULIA)
		ft_julia(&fract);
	mlx_mouse_hook(fract.win_ptr, ft_zoom, &fract);
	mlx_key_hook(fract.win_ptr, &esc_handle, &fract);
	mlx_hook(fract.win_ptr, 17, 0, ft_close, &fract);
	mlx_loop(fract.mlx_ptr);
}

void	ft_init_fractal(t_fractal *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->zoom = 4.0;
	if (!(fract->mlx_ptr))
		ft_putstr("Mlx initialization failed\n");
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!(fract->win_ptr))
		ft_putstr("Window creation failed\n");
	ft_init_image(fract);
}

void	ft_init_image(t_fractal *fract)
{
	fract->image.img = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (!fract->image.img)
		ft_putstr("Image creation failed\n");
	fract->image.addr = mlx_get_data_addr(fract->image.img,
			&fract->image.bits_per_pixel,
			&fract->image.line_length,
			&fract->image.endian);
}

int	ft_check_choice(int ac, char **av, t_fractal *fract)
{
	if (ac == 2 && ft_strcmp(av[1], "Mandelbrot") == 0)
		fract->fractal = MANDELBROT;
	else if ((ac == 4 || ac == 2) && ft_strcmp(av[1], "Julia") == 0)
	{
		fract->fractal = JULIA;
		if (av[2] && av[3])
		{
			fract->c_re = atof(av[2]);
			fract->c_im = atof(av[3]);
		}
		else if (ac == 2)
		{
			fract->c_re = -0.7269;
			fract->c_im = 0.1889;
		}
	}
	else
		return (0);
	return (1);
}
