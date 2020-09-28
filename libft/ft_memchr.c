/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:16:43 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 03:09:05 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	t = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*(t + i) == (char)c)
			return (t + i);
		i++;
	}
	return (NULL);
}
