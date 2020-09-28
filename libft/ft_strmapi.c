/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:11:40 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/08 23:34:02 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	size_t	i;
	size_t	slen;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = 0;
	while (s[slen])
		slen++;
	if (!(t = malloc(sizeof(char) * (slen + 1))))
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		t[i] = f(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
