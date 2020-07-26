/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:01:19 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/21 21:32:32 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_is_c(const char *fmt, int i);
int	ft_is_s(const char *fmt, int i);
int	ft_is_p(const char *fmt, int i);
int	ft_is_d(const char *fmt, int i);
int	ft_is_i(const char *fmt, int i);
int	ft_is_u(const char *fmt, int i);
int	ft_is_x(const char *fmt, int i);
int	ft_is_xx(const char *fmt, int i);
int ft_is_conv(const char c);
int	ft_is_flag(const char c);
int	ft_minus(const char *format, int i);
int	ft_zero(const char *format, int i);
int	ft_precision(const char *format, int i);
int	ft_nextarg(const char *format, int i, va_list ap);
int	ft_handle_flag(const char *format, int i, va_list ap);


#endif
