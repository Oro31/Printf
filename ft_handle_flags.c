/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:29:59 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/26 01:07:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_minus(const char *format, int i)
{
	if ((format[i - 1] == '*' || (format[i - 1] > 48 && format[i - 1] < 58) || 
				format[i - 1] == '.') && format[i] == '-')
		return (-1);
	if (format[i] != '-')
		return (0);
	return (1);
}

int		ft_zero(const char *format, int i)
{
	if (format[i - 1] == '*' && format[i] == '0')
		return (-1);
	if (format[i] != '0')
		return (0);
	if (ft_isdigit(format[i - 1]) || format[i - 1] == '.' || 
			format[i - 1] == '-')
		return (0);
	return (1);
}

int		ft_precision(const char *format, int i, va_list ap)
{
	int		res;

	res = 0;
	if (format[i - 1] == '.' && format[i] == '.')
		return (-1);
	if (format[i] != '.')
		return (-2);
	while (ft_isdigit(format[i + 1]))
	{
		res = res * 10;
		res = res + format[i + 1];
		i++;
	}
	if (format[i + 1] == '*' && res != 0)
		return (-1);
	if (format[i + 1] == '*' && res == 0)
	{
		res = va_arg (ap, int);
		i++;
	}
	if (!(ft_is_conv(format[i + 1])))
		return (-1);
	return (res);
}

int		ft_fieldwidth(const char *format, int i, va_list ap)
{
	int		res;

	res = 0;
	if (format[i - 1] == '*' && ((format[i] > 48 && format[i] < 58) ||
				format[i] == '*'))
		return (-1);
	if (format[i] == '*' && format[i - 1] != '.')
		return (va_arg (ap, int));
	while (ft_isdigit(format[i]) && format[i - 1] != '.')
	{
		res = res * 10;
		res = res + format[i];
		i++;
	}
	return (res);
}

int		ft_nextarg(const char *format, int i)
{
	if (format[i] == '*')
	{
		if ((format[i - 1] > 48 && format[i - 1] < 58) || format[i - 1] == '*')
			return (-1);
		return (1);
	}
	return (0);
}
