/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:24:14 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/24 03:58:39 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		res;
	int		*opt;

	res = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (!(opt = malloc(sizeof(int) * 5)))
			return (0);
		opt[0] = 0;
		opt[1] = 0;
		opt[2] = 0;
		opt[3] = 0;
		opt[4] = 0;
		while (format[i] != '%' && format[i])
		{
			ft_putchar(format[i]);
			i++;
			res++;
		}
		while (!(ft_is_conv(format[i])) && format[i])
		{
			if (format[i] == '-')
				opt[0] = 1;
			else if (format[i] == '0')
				opt[1] = 1;
			else if ((format[i] == '*' || (format[i] > 48 && 
							format[i] < 58)) && (format[i - 1] != '.' && 
								opt[2] == 0))
			{
				opt[3] = ft_fieldwidth(format, i, ap, opt);
				i = opt[4];
			}
			else if (format[i] == '.')
			{
				opt[2] = ft_precision(format, i, ap, opt);
				i = opt[4];
			}
			i++;
		}
		if (format[i] == '\0')
			return (res);
		if (format[i] == 'c')
			res = res + ft_is_c(ap, opt);
		else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
			res = res + ft_is_diu(ap, opt);
		else if (format[i] == 'p')
			res = res + ft_is_p(ap, opt);
		else if (format[i] == 's')
			res = res + ft_is_s(ap, opt);
		else if (format[i] == 'x')
			res = res + ft_is_x(ap, opt, 1);
		else if (format[i] == 'X')
			res = res + ft_is_x(ap, opt, 2);
		free(opt);
		i++;
	}
	return (res);
}

int		main()
{
	int		i;
	int		j;

	j = printf("realt %*.5d !\n", 20, 15);
	i = ft_printf("salut %*.5d !\n", 20, 15);
	printf("rea = %d \n", j);
	printf("sal = %d \n", i);
	return (0);
}	
