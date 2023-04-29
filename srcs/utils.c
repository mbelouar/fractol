void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write (1, &s[i], 1);
			i++;
		}
	}
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_print_usage(void)
{
    ft_putstr("usage: ./fractol [the number of fractal]\n");
	ft_putstr("'M'- [Mandelbrot]\n");
    ft_putstr("'J'- [Julia]\n");
}

void    ft_menu_display(void)
{
    ft_putstr("==================== THE MENU ====================\n");
    ft_putstr("usage : ./fractol [The indice of fractal]\n");
    ft_putstr("'M' - Mandelbrot set\n");
    ft_putstr("'J' - Julia set\n");
    ft_putstr("Please choose one of the available fractals\n");
}