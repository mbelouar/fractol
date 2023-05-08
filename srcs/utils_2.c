/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:10:12 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/08 00:26:36 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	esc_handle(int keycode, t_fractal *fract)
{
    if (keycode == 53)
    {
	    mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	    exit (0);  
    }
    return (0);
}

int	ft_close(t_fractal *fract)
{
    mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	exit (0); 
}

int    ft_zoom(int mouse, int x, int y, t_fractal *fract)
{
    (void)x;
    (void)y;
    if (mouse == 4 || mouse == 5)
    {
        if (mouse == 4)
            fract->zoom *= 1.2;
        else if (mouse == 5)
            fract->zoom /= 1.2;
        if (fract->fractal == MANDELBROT)
            ft_mandelbrot(fract);
        if (fract->fractal == JULIA)
            ft_julia(fract);
    }
    return (0);
}