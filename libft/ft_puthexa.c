/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:07:34 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:41:55 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hexawidth(unsigned long n)
{
	int c;

	c = 0;
	while (n >= 16)
	{
		c++;
		n = n / 16;
	}
	c++;
	return (c);
}

void	ft_puthexa(unsigned long n, int mode)
{
	char	*hexa;
	int		c;

	c = ft_hexawidth(n);
	if (mode == 1)
		hexa = "0123456789abcdef";
	else if (mode == 2)
		hexa = "0123456789ABCDEF";
	while (c > 0)
	{
		c--;
		ft_putchar(*(hexa + ((n / ft_power(16, c)) % 16)));
	}
}
