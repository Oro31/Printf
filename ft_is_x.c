/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 04:10:15 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/26 04:50:48 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(long x, int len, int *options, int mode)
{
	int		c;

	c = 0;
	while (options[2] > c + len)
	{
		ft_putchar('0');
		c++;
	}
	ft_puthexa(x, mode);
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	return (c + len);
}

static int	ft_print_precopt(long x, int len, int options, int mode)
{
	int		c;

	c = 0;
	while (options[3] > c + options[2] && options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	while (options[2] > len)
	{
		ft_putchar('0');
		c++;
		options[2]--;
	}
	ft_puthexa(x, mode);
	return (c + len)
}

static int	ft_print_zeroopt(long x, int len, int options, int mode)
{
	int		c;

	c = 0;
	while (options[3] > c + len)
	{
		ft_putchar('0');
		c++;
	}
	ft_puthexa(x, mode);
	return (c + len);
}

static int	ft_print_widthopt(long x, int len, int options, int mode)
{
	int		c;

	c = 0;
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	ft_puthexa(x, mode);
	return (c + len);
}

int		ft_is_x(va_list ap, int *options)
{
	long	x;
	int		mode;

	if (options[4] == 'X')
		mode = 2;
	else if (options[4] == 'x')
		mode = 1;
	x = va_arg(ap, long);
	len = ft_hexawidth(x);
	if (options[0] == 1)
		return (ft_print_minusopt(x, len, options, mode));
	else if (options[2] >= 0)
		return (ft_print_precopt(x, len, options, mode));
	else if (options[1] == 1)
		return (ft_print_zeroopt());
	else if (options[3] > len)
		return (ft_print_widthopt());
	ft_puthexa(x, mode);
	return (len);
}
