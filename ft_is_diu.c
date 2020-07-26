/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 02:45:34 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/26 04:42:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(long d, int len, int *options, long u)
{
	int		c;

	c = 0;
	if (d < 0)
	{
		ft_putchar('-');
		c++;
	}
	while (options[2] > len)
	{
		ft_putchar('0');
		c++;
		options[2]--;
	}
	ft_putnbr(u, 2);
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	return (c + len);
}

static int	ft_print_precopt(long d, int len, int *options, long u)
{
	int		c;

	c = 0;
	if (d < 0)
		c++;
	while (options[3] > c + options[2] && options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	if (d < 0)
		ft_putchar('-');
	while (options[2] > len)
	{
		ft_putchar('0');
		c++;
		options[2]--;
	}
	ft_putnbr(u, 2);
	return (c + len);
}

static int	ft_print_zeroopt(long d, int len, int *options, long u)
{
	int		c;

	c = 0;
	if (d < 0)
	{
		ft_putchar('-');
		c++;
	}
	while (options[3] > c + len)
	{
		ft_putchar('0');
		c++;
	}
	ft_putnbr(u, 2);
	return (c + len);
}

static int	ft_print_widthopt(long d, int len, int *options, long u)
{
	int		c;

	c = 0;
	if (d < 0)
		c++;
	while (options[3] > c + len)
	{
		ft_putchar(' ');
		c++;
	}
	if (d < 0)
		ft_putchar('-');
	ft_putnbr(u, 2);
	return (c + len);
}

int		ft_is_diu(va_list ap, int *options)
{
	long	d;
	long	u;
	size_t	len;

	d = va_arg(ap, long);
	u = d;
	if (d < 0)
		u = u * (-1);
	len = ft_nbrwidth(u);
	if (options[0] == 1)
		return (ft_print_minusopt(d, len, options, u));
	else if (options[2] >= 0)
		return (ft_print_precopt(d, len, options, u));
	else if (options[1] == 1)
		return (ft_print_zeroopt(d, len, options, u));
	else if (options[3] > len)
		return (ft_print_widthopt(d, len, options, u));
	if (d < 0)
	{
		len++;
		ft_putchar('-');
	}
	ft_putnbr(u, 2);
	return (len);
}
