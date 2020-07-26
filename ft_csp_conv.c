/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:49:08 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/22 04:31:32 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_s(const char *fmt, int i)
{
	if (fmt[i] == 's')
		return (1);
	return (0);
}

int	ft_is_c(const char *fmt, int i)
{
	if (fmt[i] == 'c')
		return (1);
	return (0);
}

int	ft_is_p(const char *fmt, int i)
{
	if (fmt[i] == 'p')
		return (1);
	return (0);
}
