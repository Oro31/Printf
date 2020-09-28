/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:36:15 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/08 23:47:31 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*t;

	if (s == NULL)
		return (NULL);
	slen = 0;
	while (s[slen])
		slen++;
	if (start >= slen)
		len = 0;
	if (!(t = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*(s + start) && i < len)
	{
		t[i] = s[start];
		i++;
		start++;
	}
	t[i] = '\0';
	return (t);
}
