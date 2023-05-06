#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 100


typedef struct mlx_ptr_t
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data_addr;
    int     size_line;
    int     bpp;
    int     endian;
} mlx_ptr_t;

typedef struct mlx_img_t
{
    mlx_ptr_t   *mlx_ptr;
    int         width;
    int         height;
    void        *img;
    char        *data_addr;
    int         bpp;
    int         size_line;
    int         endian;
} mlx_img_t;

typedef struct mlx_win_t
{
    mlx_ptr_t   *mlx_ptr;
    int         width;
    int         height;
    char        *title;
} mlx_win_t;


typedef struct {
    double x;
    double y;
} complex;

int mandelbrot(complex c) 
{
    complex z = {0, 0};
    int iter = 0;
    while (iter < MAX_ITER && (z.x * z.x + z.y * z.y) <= 4) {
        complex z_new = {z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y};
        z = z_new;
        iter++;
    }
    return iter;
}

int main() {
    mlx_ptr_t *mlx = mlx_init();
    mlx_win_t *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Set");

    mlx_img_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    int *data = (int *)mlx_get_data_addr(img, &(int){0}, &(int){0}, &(int){0});

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            complex c = {(double)i / WIDTH * 3.5 - 2.5, (double)j / HEIGHT * 2 - 1};
            int iter = mandelbrot(c);
            int color = iter == MAX_ITER ? 0x000000 : 0xFFFFFF * iter / MAX_ITER;
            data[j * WIDTH + i] = color;
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}
