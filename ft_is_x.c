/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 04:10:15 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:39:18 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(unsigned int x, int len, int *options, int mode)
{
	int		c;

	if (options[2] <= 0 && x == 0 && options[5] == 1)
		len = 0;
	c = 0;
	while (options[2] > c + len)
	{
		ft_putchar('0');
		c++;
	}
	if (!(options[2] <= 0 && x == 0 && options[5] == 1))
		ft_puthexa(x, mode);
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	return (c + len);
}

static int	ft_print_precopt(unsigned int x, int len, int *options, int mode)
{
	int		c;

	if (options[2] <= 0 && x == 0 && options[5] == 1)
		len = 0;
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
	if (!(options[2] <= 0 && x == 0 && options[5] == 1))
		ft_puthexa(x, mode);
	return (c + len);
}

static int	ft_print_zeroopt(unsigned int x, int len, int *options, int mode)
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

static int	ft_print_widthopt(unsigned int x, int len, int *options, int mode)
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

int			ft_is_x(va_list ap, int *options, int mode)
{
	unsigned int	x;
	int				len;

	x = va_arg(ap, unsigned int);
	len = ft_hexawidth(x);
	if (options[0] == 1)
		return (ft_print_minusopt(x, len, options, mode));
	else if (options[2] >= 0)
		return (ft_print_precopt(x, len, options, mode));
	else if (options[1] == 1)
		return (ft_print_zeroopt(x, len, options, mode));
	else if (options[3] > len)
		return (ft_print_widthopt(x, len, options, mode));
	ft_puthexa(x, mode);
	return (len);
}
