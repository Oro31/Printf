/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:01:19 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/25 04:14:20 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_is_c(va_list ap, int *options, int mode);
int	ft_is_s(va_list ap, int *options);
int	ft_is_p(va_list ap, int *options);
int	ft_is_di(va_list ap, int *options);
int ft_is_u(va_list ap, int *options);
int	ft_is_x(va_list ap, int *options, int mode);
int ft_is_conv(const char c);
int	ft_is_flag(const char c);
int	ft_precision(const char *format, int i, va_list ap, int *opt);
int	ft_fieldwidth(const char *format, int i, va_list ap, int *opt);
int	ft_handle_options(const char *format, int *opt, int i, va_list ap);
int	ft_conv(const char *format, int *opt, int i, va_list ap);
int	*ft_init_opt(void);

#endif
