/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:32:00 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/24 00:48:04 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_putnbr(char *s, int n, int c)
{
	int	m;

	m = n;
	if (n < 0)
		m = m * (-1);
	c--;
	while (c > 0)
	{
		s[c] = (m % 10) + 48;
		m = m / 10;
		c--;
	}
	if (n < 0)
		s[0] = '-';
	else
		s[0] = (m % 10) + 48;
	return (s);
}

static char	*ft_handle_min(void)
{
	char	*r;

	if (!(r = malloc(sizeof(char) * 12)))
		return (NULL);
	r[0] = '-';
	r[1] = '2';
	r[2] = '1';
	r[3] = '4';
	r[4] = '7';
	r[5] = '4';
	r[6] = '8';
	r[7] = '3';
	r[8] = '6';
	r[9] = '4';
	r[10] = '8';
	r[11] = '\0';
	return (r);
}

char		*ft_itoa(int n)
{
	char	*s;
	size_t	m;
	size_t	c;

	c = 0;
	if (n == -2147483648)
		return (ft_handle_min());
	if (n < 0)
	{
		m = n * (-1);
		c++;
	}
	else
		m = n;
	while (m >= 10)
	{
		c++;
		m = m / 10;
	}
	c++;
	if (!(s = malloc(sizeof(char) * (c + 1))))
		return (NULL);
	s[c] = '\0';
	return (ft_itoa_putnbr(s, n, c));
}
