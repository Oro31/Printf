/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:50:35 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/21 23:59:28 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_count_args(const char *fmt)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			c++;
	}
	return (c);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;
	int	nb_arg;
	char	*s;
	char	c;
	int	d;

	va_start(ap, format);
	nb_arg = 0;
	i = 0;
	while (nb_arg < ft_count_args(format))
	{
		while (format[i] && format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '\0')
			return (i);
		if (ft_is_s(format, i))
		{
			s = va_arg (ap, char *);
			printf("chaine %s \n", s);
			nb_arg++;
		}
		else if (ft_is_d(format, i))
		{
			d = va_arg (ap, int);
			ft_putnbr(d);
			nb_arg++;
		}
		else if (ft_is_c(format, i))
		{
			c = (char) va_arg (ap, int);
			ft_putchar(c);
			nb_arg++;
		}
		else
			printf("not a good format");
/*		while (!(ft_is_conv(format[i])))
			i++;*/
		i++;
	}
	va_end(ap);
	return (i);
}
