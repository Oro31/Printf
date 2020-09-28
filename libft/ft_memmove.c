/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:16:11 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 04:13:32 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	if (d != NULL || s != NULL)
	{
		if (d < s)
		{
			i = 0;
			while (i++ < n)
				*(d + i - 1) = *(s + i - 1);
		}
		else
		{
			while (n-- > 0)
			{
				*(d + n) = *(s + n);
			}
		}
	}
	return (dest);
}
