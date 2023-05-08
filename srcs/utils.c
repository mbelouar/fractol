/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:33:31 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/01 19:33:31 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

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

double ft_atoif(char *str) {
    double sign;
    double res;
    int i;

	i = 0;
	res = 0.0;
	sign = 1.0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
	{
        sign = -1.0;
        i++;
	}
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
        res *= 10.0;
        res += (double)(str[i] - '0');
        i++;
    }
    return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void    ft_menu_display(void)
{
    ft_putstr("==================== THE MENU ====================\n");
    ft_putstr("usage : ./fractol [The fractal name]\n");
    ft_putstr("'Mandelbrot' - Mandelbrot set\n");
    ft_putstr("'Julia' - Julia set\n");
    ft_putstr("Please choose one of the available fractals\n");
}