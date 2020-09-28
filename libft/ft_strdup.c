/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:19:36 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 03:27:16 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (!(d = malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		*(d + i) = *(s + i);
		i++;
	}
	d[i] = '\0';
	return (d);
}
