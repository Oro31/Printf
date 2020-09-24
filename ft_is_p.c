/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 01:56:24 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/24 00:43:46 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(int len, int *options, void *p)
{
	int		c;

	c = len + 2;
	ft_putmem(p);
	while (options[3] > len + 2)
	{
		ft_putchar(' ');
		c++;
		options[3]--;
	}
	return (c);
}

static int	ft_print_zeroopt(unsigned long n, int len, int *options)
{
	int		c;

	c = len + 2;
	ft_putchar('0');
	ft_putchar('x');
	while (options[3] > len + 2)
	{
		ft_putchar('0');
		c++;
		options[3]--;
	}
	ft_puthexa(n, 1);
	return (c);
}

static int	ft_print_widthopt(int len, int *options, void *p)
{
	int		c;

	c = len + 2;
	while (options[3] > len + 2)
	{
		ft_putchar(' ');
		c++;
		options[3]--;
	}
	ft_putmem(p);
	return (c);
}

int		ft_is_p(va_list ap, int *options)
{
	void			*p;
	unsigned char	*add;
	unsigned long	n;
	size_t			len;

	p = va_arg(ap, void *);
	add = (unsigned char *)p;
	n = (unsigned long)add;
	len = ft_hexawidth(n);
	if (options[0] == 1)
		return (ft_print_minusopt(len, options, p));
	else if (options[1] == 1)
		return (ft_print_zeroopt(n, len, options));
	else if (options[3] > len)
		return (ft_print_widthopt(len, options, p));
	else
		ft_putmem(p);
	return (len + 2);
}
