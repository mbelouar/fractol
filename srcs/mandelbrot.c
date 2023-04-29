#include "fractol.h"

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
int     ft_mandelbrot(t_fractal *fract)
{
    double  mod;
    double  tmp;
    double  z_re2;
    double  z_im2;
    int     count;

    z_re2 = fract->z_re * fract->z_re;
    z_im2 = fract->z_im * fract->z_im;
    mod = z_re2 + z_im2;
    tmp = 0;
    count = 0;
    while (mod < 4 && count < fract->max_iter)
    {
        tmp = fract->z_re;
        fract->z_re = z_re2 + fract->c_re;
        fract->z_im = 2 * fract->z_im * tmp + fract->c_im;
        mod = z_re2 + z_im2;
        count++;
    }
    return (count);
}