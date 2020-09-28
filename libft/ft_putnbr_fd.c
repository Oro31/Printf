/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:39:19 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/24 00:50:35 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_fd_putnbr(int n, char *res)
{
	int		m;
	int		l;

	m = n;
	l = 0;
	while (m >= 10)
	{
		m = m / 10;
		l++;
	}
	res[l + 1] = '\0';
	m = n;
	while (l >= 0)
	{
		res[l] = (m % 10) + 48;
		m = m / 10;
		l--;
	}
	return (res);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	itoa[11];
	int		i;

	if (fd != -1)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			if (n < 0)
			{
				n = n * (-1);
				write(fd, "-", 1);
			}
			ft_fd_putnbr(n, itoa);
			i = 0;
			while (itoa[i])
			{
				c = itoa[i];
				write(fd, &c, 1);
				i++;
			}
		}
	}
}
