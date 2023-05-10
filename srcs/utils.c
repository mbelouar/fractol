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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	ft_menu_display(void)
{
	ft_putstr("==================== THE MENU ====================\n");
	ft_putstr("usage : ./fractol [The fractal name]\n");
	ft_putstr("'Mandelbrot' - Mandelbrot set\n");
	ft_putstr("   'Julia'   - Julia set\n\n");
	ft_putstr("In case you choose julia set, \n");
	ft_putstr("you can put the value of the c constant\n");
	ft_putstr("usage : ./fractol Julia ");
	ft_putstr("[real part of c] [imaginary part of c]\n");
	ft_putstr("This is some famous julia set coordinates :\n");
	ft_putstr("Julia set for fc : c = −0.4 + 0.6i\n");
	ft_putstr("Julia set for fc : c = 0.285 + 0i\n");
	ft_putstr("Julia set for fc : c = 0.285 + 0.01i\n");
	ft_putstr("Julia set for fc : c = 0.45 + 0.1428i\n");
	ft_putstr("Julia set for fc : c = −0.70176 − 0.3842i\n");
	ft_putstr("Julia set for fc : c = −0.835 − 0.2321i\n");
	ft_putstr("Julia set for fc : c = −0.7269 + 0.1889i\n");
	ft_putstr("Julia set for fc : c = −0.8 + 0.156i\n");
	ft_putstr("Julia set for fc : c = -0.1 + 0.651\n");
	ft_putstr("Julia set for fc : c = -0.75 + 0.11\n");
	ft_putstr("Julia set for fc : c = −0.8i\n");
	ft_putstr("Please choose one of the available fractals\n");
}
