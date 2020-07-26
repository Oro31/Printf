/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:53:35 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/26 01:07:53 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		ft_is_flag(const char c)
{
	if (ft_isdigit(c) || c == '-' || c == '*' || c == '.')
		return (1);
	return (0);
}

/*int		ft_handle_flags(const char *fmt, int i, va_list ap, int	*option)
{
	if (ft_minus(fmt, i) == -1 || ft_zero(fmt, i) == -1 ||
			ft_precision(fmt, i, ap) == -1 || ft_fieldwidth(fmt, i, ap) == -1 |
			ft_nextarg(fmt, i) == -1 || !(ft_is_flag(fmt[i])))
		return (0);
	if (ft_precision(fmt, i, ap) > 0 && option[2] > 0)
		return (0);
	if (ft_fieldwidth(fmt, i, ap) > 0 && option[3] > 0)
		return (0);
	return (1);
}*/

int		ft_printf_option(const char *fmt, int i, va_list ap, int *option)
{
	if (!(option = malloc(sizeof(int) * 5)))
		return (NULL);
	ft_bzero(option, 5);
	while (!(ft_is_conv(fmt[i])))
	{
		if (!(ft_is_flag(fmt[i])))
			return (-1);
		option[0] = ft_minus(fmt, i);
		option[1] = ft_zero(fmt, i);
		option[2] = ft_precision(fmt, i, ap);
		option[3] = ft_fieldwidth(fmt, i, ap);
		if (option[0] == -1 || option[1] == -1 || option[2] == -1 ||
			   	option[3] == -1)
			return (-1);
		i++;
	}
	option[4] = i;
	if ((option[0] + option[1] + option[2] + option[3]) == 0)
		return (0);
	return (1);
}

void	ft_handle_options(const char *fmt, int i, va_list ap)
{
	int		*option;
	size_t	arglen;

	if (ft_printf_option(fmt, i, ap, option) == 0)
		ft_printarg(ap);
	arglen = ft_arglen(fmt[option[4]], ap);
	if (option[0] == 1)
	{
		while (option[2] > arglen)
		{
			ft_putchar('0');
			option[2]--;
			option[3]--;
		}
		ft_printarg(ap);
		while (option[3] > arglen)
		{
			ft_putchar(' ');
			option[3]--;
		}
	}
	else if (option[2] > 0)
	{
		while (option[3] > option[2] && option[3] >	arglen)
		{
			ft_putchar(' ');
			option[3]--;
		}
		while (option[2] > arglen)
		{
			ft_putchar('0');
			option[2]--;
		}
		ft_printarg(ap);
	}
	else if (option[1] == 1)
	{
		while (option[3] > arglen)
		{
			ft_putchar('0');
			option[3]--;
		}
		ft_printarg(ap);
	}
}
