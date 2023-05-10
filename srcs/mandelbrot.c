/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:26:59 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/10 07:08:33 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
Here's the Mandelbrot's algorithm
i define the z_im2 and z_re2 to simplifiy the square value of each one
the tmp var just because after modification of z_re
we need the previous value of z_re
when we calculate the new value of z_im
the count var helps to iterate until the max_iter
mod = sqrt(z_re2 + z_im2) > 2
 if the value of Z ever goes farther away than 2 from the origin,
 c doesn't belong to the set
*/
int	calculate_mandelbrot(t_fractal *fract)
{
	double	z_re;
	double	z_im;
	double	tmp;
	double	mod;
	int		count;

	z_re = 0;
	z_im = 0;
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

/**
 * The first thing to do when we are going to draw the Mandelbrot set in an image
 * is to set the equivalence between pixel coordinates and complex numbers.
 * This means that each pixel in our image has to represent a complex number
 * Then we will color that pixel according to
 * whether it belongs to the Mandelbrot set or not.
 * However, I Just define the four corners and calculate.
 */
void	ft_mandelbrot(t_fractal *fract)
{
	fract->scale = fract->zoom / WIDTH;
	fract->max_iter = 50;
	fract->z_re = 0;
	fract->z_im = 0;
	fract->mouse_y = -1;
	while (++fract->mouse_y < HEIGHT)
	{
		fract->mouse_x = -1;
		while (++fract->mouse_x < WIDTH)
		{
			fract->c_re = (fract->mouse_x - WIDTH / 2.0) * fract->scale;
			fract->c_im = (fract->mouse_y - HEIGHT / 2.0) * fract->scale;
			fract->iter = calculate_mandelbrot(fract);
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
