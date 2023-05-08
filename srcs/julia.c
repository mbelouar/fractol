/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:29:26 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/08 01:16:39 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    julia_init(t_fractal *fract, char **av)
{
    if (av[2] && av[3])
    {
        fract->c_re = ft_atoif(av[2]);
        fract->c_im = ft_atoif(av[3]);
    }
    else
    {
        fract->c_re = -0.7269;
        fract->c_im = 0.1889;
    }
}

int calculate_julia(t_fractal *fract)
{
    double z_re = (fract->mouse_x - WIDTH / 2.0) * fract->scale;
    double z_im = (fract->mouse_y - HEIGHT / 2.0) * fract->scale;
    double tmp;
    double mod;
    int count;
    
    z_re = (fract->mouse_x - WIDTH / 2.0) * fract->scale;
    z_im = (fract->mouse_y - HEIGHT / 2.0) * fract->scale;
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

void    ft_julia(t_fractal *fract)
{
    fract->scale = fract->zoom / WIDTH;
    fract->max_iter = 50;
    // fract->c_re = -0.7269;
    // fract->c_im = 0.1889;
    fract->mouse_y = -1;

    while (++fract->mouse_y < HEIGHT)
    {
        fract->mouse_x = -1;
        while (++fract->mouse_x < WIDTH)
        {
            fract->iter = calculate_julia(fract);
            if (fract->iter == fract->max_iter)  // inside the mandelbrot set
                plot_point(fract, fract->mouse_x, fract->mouse_y, 0x000000);
            else  // outside mandelbrot set
                plot_point(fract, fract->mouse_x, fract->mouse_y,
                                get_color(fract, fract->iter));
        }
    }
    mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image.img, 0, 0);
}
