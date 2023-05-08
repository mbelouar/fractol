/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:29:26 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/08 22:24:34 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_julia(t_fractal *fract)
{
	double	z_re;
	double	z_im;
	double	tmp;
	double	mod;
	int		count;

	z_re = (fract->mouse_x - WIDTH / 2.0) * fract->scale;
	z_im = (fract->mouse_y - HEIGHT / 2.0) * fract->scale;
	mod = z_re * z_re + z_im * z_im;
	count = 0;
	while (mod < 4 && count < fract->max_iter)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + fract->c_re;
		z_im = 2 * tmp * z_im + fract->c_im;
		mod = z_re * z_re + z_im * z_im;
		count++;
	}
	return (count);
}

void	ft_julia(t_fractal *fract)
{
	fract->scale = fract->zoom / WIDTH;
	fract->max_iter = 50;
	fract->mouse_y = -1;
	while (++fract->mouse_y < HEIGHT)
	{
		fract->mouse_x = -1;
		while (++fract->mouse_x < WIDTH)
		{
			fract->iter = calculate_julia(fract);
			if (fract->iter == fract->max_iter)
				plot_point(fract, fract->mouse_x, fract->mouse_y, 0x000000);
			else
				plot_point(fract, fract->mouse_x, fract->mouse_y,
					get_color(fract, fract->iter));
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
		fract->image.img, 0, 0);
}
