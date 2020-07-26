/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:49:10 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/25 22:36:25 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_options(const char *fmt, int i, va_list ap)
{
	int		*options;

	if (ft_printf_option(fmt, i, ap, option) == 0)
		ft_printarg(ap);
	if (option[0] == 1)
		ft_print_minusopt(options, ap);
	else if (option[2] > 0)
		ft_print_precopt(options, ap);
	else if (option[1] == 1)
		ft_print_zeroopt(options, ap);
	else if (option[3] > 0)
		ft_print_widthopt(options, ap);
}
