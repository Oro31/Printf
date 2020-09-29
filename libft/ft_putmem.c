/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:15:35 by rvalton           #+#    #+#             */
/*   Updated: 2020/09/29 03:40:56 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *address)
{
	unsigned char	*add;
	unsigned long	n;

	add = (unsigned char *)address;
	n = (unsigned long)add;
	ft_putchar('0');
	ft_putchar('x');
	ft_puthexa(n, 1);
}
