/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:41:39 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/10 07:08:53 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * This function plots a single point in the window with the specified color.
 * It takes in the x and y coordinates of the point, as well as the color to
 * use for the pixel. The function calculates the memory address of the pixel
 * in the window using the WIDTH and HEIGHT of the window, and then sets the
 * color of the pixel to the specified value.
 */
void	plot_point(t_fractal *fract, int x, int y, int color)
{
	char	*addr;

	addr = fract->image.addr + (y * fract->image.line_length + x
			* (fract->image.bits_per_pixel / 8));
	*(unsigned int *)addr = (unsigned int)color;
}

/**
 * This function takes in a fractal struct and the number of iterations
 * it took for a point to escape the Mandelbrot set. It then uses the
 * number of iterations to calculate a color to represent the point.
 * The color calculation is based on the number of iterations and the
 * escape time algorithm. The resulting color is then returned.
 * the value of escp between 0 and 1 based on the number of iterations
 * it represents the portion of the way the point has "escaped"
 */
int	get_color(t_fractal *fract, int iter)
{
	int		color;
	double	escp;

	escp = (double)iter / (double)fract->max_iter;
	fract->color.r = (int)(255 * (1 - escp) * (1 - escp)
			* (1 - escp) * (1 - escp));
	fract->color.r = (int)(255 * 8 * (1 - escp) * (1 - escp)
			* (1 - escp) * escp);
	fract->color.b = (int)(255 * 15 * (1 - escp) * (1 - escp) * escp * escp);
	color = (fract->color.r << 16) + (fract->color.r << 8) + fract->color.b;
	return (color);
}
