/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:51:12 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 03:10:32 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;

	len = 0;
	slen = 0;
	while (src[slen])
		slen++;
	while (*dst && size > 0)
	{
		dst++;
		len++;
		size--;
	}
	while (*src && size-- > 1)
	{
		*dst++ = *src++;
	}
	if (size == 0 || *src == 0)
		*dst = '\0';
	return (slen + len);
}
