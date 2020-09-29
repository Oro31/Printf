/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:48:22 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:38:59 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minusopt(char *s, int len, int *options)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (options[2] < 0)
		options[2] = len;
	while (options[2] > 0 && i < len)
	{
		ft_putchar(*(s + i));
		i++;
		options[2]--;
	}
	c = i;
	while (options[3] > i)
	{
		ft_putchar(' ');
		options[3]--;
		c++;
	}
	return (c);
}

static int	ft_print_zeroopt(char *s, int len, int *options)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (options[2] < len && options[2] > 0)
		len = options[2];
	while (options[3] > len)
	{
		ft_putchar('0');
		c++;
		options[3]--;
	}
	while (len - i > 0)
	{
		ft_putchar(*(s + i));
		i++;
		c++;
	}
	return (c);
}

static int	ft_print_precopt(char *s, int *options)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (options[3] > options[2])
	{
		ft_putchar(' ');
		c++;
		options[3]--;
	}
	while (i < options[2])
	{
		ft_putchar(*(s + i));
		i++;
		c++;
	}
	return (c);
}

static int	ft_print_widthopt(char *s, int len, int *options)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (options[3] > len)
	{
		ft_putchar(' ');
		c++;
		options[3]--;
	}
	while (len > 0)
	{
		ft_putchar(*(s + i));
		i++;
		c++;
		len--;
	}
	return (c);
}

int			ft_is_s(va_list ap, int *options)
{
	char	*s;
	int		len;

	if (!(s = va_arg(ap, char *)))
		s = "(null)";
	len = ft_strlen(s);
	if (options[0] == 1)
		return (ft_print_minusopt(s, len, options));
	else if (options[1] == 1)
		return (ft_print_zeroopt(s, len, options));
	else if (options[2] < len && options[2] >= 0)
		return (ft_print_precopt(s, options));
	else if (options[3] > len)
		return (ft_print_widthopt(s, len, options));
	ft_putstr(s);
	return (len);
}
