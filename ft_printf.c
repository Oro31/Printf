/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 04:21:09 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/25 02:01:14 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		res;
	int		*opt;

	res = 0;
	va_start(ap, format);
	i = -1;
	while (format[++i])
	{
		if (!(opt = ft_init_opt()))
			return (0);
		while (format[i] != '%' && format[i])
		{
			ft_putchar(format[i]);
			i++;
			res++;
		}
		i = ft_handle_options(format, opt, i, ap);
		if (format[i] == '\0')
			return (res);
		res = res + ft_conv(format, opt, i, ap);
		free(opt);
	}
	return (res);
}
