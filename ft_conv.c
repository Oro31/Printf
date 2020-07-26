/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:22:48 by rvalton           #+#    #+#             */
/*   Updated: 2020/07/25 23:40:57 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_is_conv(const char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "cspdiuxX";
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strarg(va_list ap, char c)
{
	char	*s;
	size_t	size;

	if (c == 'c')
		size = 1;
	else if (c == 's')
	{
		
	}
	else if (c == 'p')
	{
	
	}
}

int		ft_arglen(char c, va_list ap)
{
	if (c == 'c')
		return (1);
	else if (c == 'd' || c == 'i')
	{
		d = va_arg (ap, int)
	}
}
