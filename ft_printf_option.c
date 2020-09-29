/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:53:35 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:40:14 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_conv(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		*ft_init_opt(void)
{
	int		*opt;
	int		i;

	i = 0;
	if (!(opt = malloc(sizeof(int) * 6)))
		return (NULL);
	while (i < 6)
	{
		opt[i] = -1;
		i++;
	}
	return (opt);
}

int		ft_handle_options(const char *format, int *opt, int i, va_list ap)
{
	if (format[i] == '%')
		i++;
	while (!(ft_is_conv(format[i])) && format[i] && format[i] != '%')
	{
		if (format[i] == '-')
			opt[0] = 1;
		else if (format[i] == '0')
			opt[1] = 1;
		else if ((format[i] == '*' || (format[i] > 48 &&
						format[i] < 58)) && (format[i - 1] != '.' &&
							opt[2] == -1))
		{
			opt[3] = ft_fieldwidth(format, i, ap, opt);
			i = opt[4];
		}
		else if (format[i] == '.')
		{
			opt[5] = 1;
			opt[2] = ft_precision(format, i, ap, opt);
			i = opt[4];
		}
		i++;
	}
	return (i);
}

int		ft_conv(const char *format, int *opt, int i, va_list ap)
{
	if (format[i] == 'c')
		return (ft_is_c(ap, opt, 0));
	else if (format[i] == '%')
		return (ft_is_c(ap, opt, 1));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_is_di(ap, opt));
	else if (format[i] == 'u')
		return (ft_is_u(ap, opt));
	else if (format[i] == 'p')
		return (ft_is_p(ap, opt));
	else if (format[i] == 's')
		return (ft_is_s(ap, opt));
	else if (format[i] == 'x')
		return (ft_is_x(ap, opt, 1));
	else if (format[i] == 'X')
		return (ft_is_x(ap, opt, 2));
	return (0);
}
