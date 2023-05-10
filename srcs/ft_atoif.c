/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 07:04:57 by mbelouar          #+#    #+#             */
/*   Updated: 2023/05/10 07:26:17 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	process_digits(char *str, int *i, int *num_digits)
{
	double	result;

	result = 0.0;
	while (str[*i] != '\0' && str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (double)(str[*i] - '0');
		(*i)++;
		(*num_digits)++;
	}
	return (result);
}

void	process_sign(char *str, int *i, double *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		*sign = -1.0;
		(*i)++;
	}
}

void	adjust_decimal(double *result, int num_digits)
{
	int	k;

	k = 0;
	while (k < num_digits - 1)
	{
		*result /= 10.0;
		k++;
	}
}

double	ft_atoif(char *str)
{
	double	result;
	double	sign;
	int		i;
	int		num_digits;
	int		is_decimal;

	result = 0.0;
	sign = 1.0;
	i = 0;
	num_digits = 0;
	is_decimal = 0;
	process_sign(str, &i, &sign);
	result = process_digits(str, &i, &num_digits);
	if (str[i] == '.')
	{
		is_decimal = 1;
		i++;
		result = process_digits(str, &i, &num_digits);
	}
	if (is_decimal)
		adjust_decimal(&result, num_digits);
	result *= sign;
	return (result);
}
