/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:53:35 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/24 00:33:32 by rvalton          ###   ########.fr       */
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

int		ft_is_flag(const char c)
{
	if (ft_isdigit(c) || c == '-' || c == '*' || c == '.')
		return (1);
	return (0);
}
