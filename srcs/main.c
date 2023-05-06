/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:33:00 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/06 00:48:17 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int ac, char **av)
{
	t_fractal	fract;

	if (ac != 2 || ft_check_choice(av[1], &fract) == 0)
	{
		ft_menu_display();
		exit(1);
	}
	ft_init_fractal(&fract);
	set_complex_pixel_and_draw(&fract);
	mlx_loop(fract.mlx_ptr);
}


void	ft_init_fractal(t_fractal *fract)
{
	fract->mlx_ptr = mlx_init();
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

int		ft_check_choice(char *name, t_fractal *fract)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		fract->fractal = MANDELBROT;
	else if (ft_strcmp(name, "Julia") == 0)
		fract->fractal = JULIA;
	else
		return (0);
	return (1);
}