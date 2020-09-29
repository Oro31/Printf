/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 02:45:34 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:38:41 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(unsigned int u, int len, int *options)
{
	int		c;

	if (options[2] <= 0 && u == 0 && options[5] == 1)
		len = 0;
	c = 0;
	while (options[2] > len)
	{
		ft_putchar('0');
		c++;
		options[2]--;
	}
	if (!(options[2] <= 0 && u == 0 && options[5] == 1))
		ft_putnbr(u, 2);
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	return (c + len);
}

static int	ft_print_precopt(unsigned int u, int len, int *options)
{
	int		c;

	if (options[2] <= 0 && u == 0 && options[5] == 1)
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
	if (!(options[2] <= 0 && u == 0 && options[5] == 1))
		ft_putnbr(u, 2);
	return (c + len);
}

static int	ft_print_zeroopt(unsigned int u, int len, int *options)
{
	int		c;

	c = 0;
	while (options[3] > c + len)
	{
		ft_putchar('0');
		c++;
	}
	ft_putnbr(u, 2);
	return (c + len);
}

static int	ft_print_widthopt(unsigned int u, int len, int *options)
{
	int		c;

	c = 0;
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	ft_putnbr(u, 2);
	return (c + len);
}

int			ft_is_u(va_list ap, int *options)
{
	unsigned int	d;
	unsigned int	u;
	int				len;

	d = va_arg(ap, int);
	u = d;
	len = ft_nbrwidth(u);
	if (options[0] == 1)
		return (ft_print_minusopt(u, len, options));
	else if (options[2] >= 0)
		return (ft_print_precopt(u, len, options));
	else if (options[1] == 1)
		return (ft_print_zeroopt(u, len, options));
	else if (options[3] > len)
		return (ft_print_widthopt(u, len, options));
	ft_putnbr(u, 2);
	return (len);
}
