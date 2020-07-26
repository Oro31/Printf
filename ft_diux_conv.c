/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diux_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:55:09 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/22 04:32:04 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_d(const char *fmt, int i)
{
	if (fmt[i] == 'd')
		return (1);
	return (0);
}

int	ft_is_i(const char *fmt, int i)
{
	if (fmt[i] == 'i')
		return (1);
	return (0);
}

int	ft_is_u(const char *fmt, int i)
{
	if (fmt[i] == 'u')
		return (1);
	return (0);
}

int	ft_is_x(const char *fmt, int i)
{
	if (fmt[i] == 'x')
		return (1);
	return (0);
}

int	ft_is_xx(const char *fmt, int i)
{
	if (fmt[i] == 'X')
		return (1);
	return (0);
}
