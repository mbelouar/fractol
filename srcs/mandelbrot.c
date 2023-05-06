/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:26:59 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/06 00:47:08 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Here, i just set eash algo to its fractal
 * if the fractal is the MANDELBROT wi call the ft_mandelbrot
 * that do its routine with the specific max_iter and return the number of iterations
 */

int     ft_algo_of_each_fract(t_fractal *fract)
{
    int iter;

    if (fract->fractal == MANDELBROT)
        iter = calculate_mandelbrot(fract);
    // else if (fract->fractal == JULIA)
    //     iter = ft_julia(fract);
    return (iter);
}

/**
 * This function plots a single point in the window with the specified color.
 * It takes in the x and y coordinates of the point, as well as the color to
 * use for the pixel. The function calculates the memory address of the pixel
 * in the window using the WIDTH and HEIGHT of the window, and then sets the
 * color of the pixel to the specified value.
 */

void plot_point(t_fractal *fract, int x, int y, int color)
{
    char *addr;

    addr = fract->image.addr + (y * fract->image.line_length 
                    + x * (fract->image.bits_per_pixel / 8));
    *(unsigned int*)addr = (unsigned int)color;
}

/**
 * This function takes in a fractal struct and the number of iterations
 * it took for a point to escape the Mandelbrot set. It then uses the 
 * number of iterations to calculate a color to represent the point.
 * The color calculation is based on the number of iterations and the
 * escape time algorithm. The resulting color is then returned.
 * the value of escp between 0 and 1 based on the number of iterations
 * it represents the portion of the way the point has "escaped the Mandelbrot set"
 */

int get_color(t_fractal *fract, int iter)
{
    int color;
    double escp;

    escp = (double)iter / (double)fract->max_iter;
    fract->color.r = (int)(255 * (1 - escp) * (1 - escp) * (1 - escp) * (1 - escp));
    fract->color.r = (int)(255 * 8 * (1 - escp) * (1 - escp) * (1 - escp) * escp);
    fract->color.b = (int)(255 * 15 * (1 - escp) * (1 - escp) * escp * escp);
    color = (fract->color.r << 16) + (fract->color.r << 8) + fract->color.b;

    return (color);
}

/*
Here's the Mandelbrot's algorithm 
i define the z_im2 and z_re2 to simplifiy the square value of each one
the tmp var just because after modification of z_re we need the previous value of z_re
when we calculate the new value of z_im
the count var helps to iterate until the max_iter
mod = sqrt(z_re2 + z_im2) > 2
 if the value of Z ever goes farther away than 2 from the origin, 
 c doesn't belong to the set
*/
int calculate_mandelbrot(t_fractal *fract)
{
    double z_re = 0;
    double z_im = 0;
    double tmp;
    double mod;
    int count;
    
    mod = z_re * z_re + z_im * z_im;
    count = 0;
    while (mod < 4 && count < fract->max_iter)
    {
        tmp = z_re;
        z_re = z_re * z_re - z_im * z_im + fract->c_re;
        z_im = 2 * tmp * z_im +  fract->c_im;
        mod = z_re * z_re + z_im * z_im;
        count++;
    }
    return (count);
}

/**
 * The first thing to do when we are going to draw the Mandelbrot set in an image
 * is to set the equivalence between pixel coordinates and complex numbers.
 * This means that each pixel in our image has to represent a complex number
 * Then we will color that pixel according to whether it belongs to the Mandelbrot set or not.
 * However, I Just define the four corners and calculate.
 */

void    set_complex_pixel_and_draw(t_fractal *fract)
{
    fract->scale = 4.0 / WIDTH;
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
            if (fract->iter == fract->max_iter)  // inside the mandelbrot set
                plot_point(fract, fract->mouse_x, fract->mouse_y, 0x000000);
            else  // outside mandelbrot set
                // printf("..\n");
                plot_point(fract, fract->mouse_x, fract->mouse_y,
                                get_color(fract, fract->iter));
        }
    }
    mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image.img, 0, 0);
}
