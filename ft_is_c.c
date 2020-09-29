/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 01:37:58 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:36:16 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(char c, int *options)
{
	int		i;

	i = 1;
	ft_putchar(c);
	while (options[3] > 1)
	{
		ft_putchar(' ');
		i++;
		options[3]--;
	}
	return (i);
}

static int	ft_print_zeroopt(char c, int *options)
{
	int		i;

	i = 1;
	while (options[3] > 1)
	{
		ft_putchar('0');
		i++;
		options[3]--;
	}
	ft_putchar(c);
	return (i);
}

static int	ft_print_widthopt(char c, int *options)
{
	int		i;

	i = 1;
	while (options[3] > 1)
	{
		ft_putchar(' ');
		i++;
		options[3]--;
	}
	ft_putchar(c);
	return (i);
}

int			ft_is_c(va_list ap, int *options, int mode)
{
	char	c;

	if (mode == 0)
		c = (char)va_arg(ap, int);
	else if (mode == 1)
		c = '%';
	if (options[0] == 1)
		return (ft_print_minusopt(c, options));
	else if (options[1] == 1)
		return (ft_print_zeroopt(c, options));
	else if (options[3] > 1)
		return (ft_print_widthopt(c, options));
	else
		ft_putchar(c);
	return (1);
}
