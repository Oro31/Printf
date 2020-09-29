/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 07:24:39 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:41:22 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrwidth(long n)
{
	int		c;

	c = 0;
	if (n == INT_MIN)
		return (10);
	while (n >= 10)
	{
		c++;
		n = n / 10;
	}
	c++;
	return (c);
}

static int	ft_putmin(int n)
{
	char	*min;
	int		i;

	i = 0;
	min = "-2147483648";
	if (n != -2147483648)
		return (0);
	else
	{
		while (min[i])
		{
			ft_putchar(min[i]);
			i++;
		}
	}
	return (1);
}

static int	ft_putunbr(unsigned int n)
{
	int		c;

	c = ft_nbrwidth(n);
	while (c > 0)
	{
		c--;
		ft_putchar(((n % ft_power(10, c + 1)) / ft_power(10, c)) + 48);
	}
	return (1);
}

static int	ft_putsnbr(int n)
{
	int		c;

	if (ft_putmin(n))
		return (1);
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	c = ft_nbrwidth(n);
	while (c > 0)
	{
		c--;
		ft_putchar(((n % ft_power(10, c + 1)) / ft_power(10, c)) + 48);
	}
	return (1);
}

void		ft_putnbr(long nbr, int mode)
{
	int		i;
	int		a;
	char	*error;

	i = 0;
	error = "erreur";
	a = 0;
	if (mode == 1)
		a = ft_putsnbr(nbr);
	else if (mode == 2)
		a = ft_putunbr(nbr);
	if (a != 1)
		ft_putstr(error);
}
