/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:35:53 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 01:22:00 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	if (src == NULL || dst == NULL)
		return (0);
	slen = 0;
	while (src[slen])
		slen++;
	if (dstsize == 0)
		return (slen);
	i = 0;
	while (i < (dstsize - 1) && i < slen)
	{
		if (src[i])
			dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
