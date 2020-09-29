/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:29:59 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:35:21 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(const char *format, int i, va_list ap, int *opt)
{
	int		res;

	res = 0;
	if (format[i + 1] == '*')
	{
		opt[4] = i + 1;
		res = va_arg(ap, int);
		if (res < 0)
			opt[5] = 0;
		return (res);
	}
	while (ft_isdigit(format[i + 1]))
	{
		res = res * 10;
		res = res + (format[i + 1] - 48);
		i++;
	}
	if (res < 0)
		opt[5] = 0;
	opt[4] = i;
	return (res);
}

int		ft_fieldwidth(const char *format, int i, va_list ap, int *opt)
{
	int		res;
	int		j;

	j = 0;
	res = 0;
	if (format[i] == '*')
	{
		opt[4] = i;
		j = va_arg(ap, int);
		if (j < 0)
		{
			opt[0] = 1;
			j = j * -1;
		}
		return (j);
	}
	while (ft_isdigit(format[i]))
	{
		res = res * 10;
		res = res + (format[i] - 48);
		i++;
	}
	opt[4] = i - 1;
	return (res);
}
