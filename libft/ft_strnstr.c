/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:21 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 03:22:50 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s2len;

	if (*s2 == '\0')
		return ((char *)s1);
	s2len = 0;
	while (s2[s2len])
		s2len++;
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (j < s2len && s1[i + j] == s2[j] && (i + j) < n)
				j++;
			if (j == s2len)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
