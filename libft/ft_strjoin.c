/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:48:24 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 01:20:26 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_string(char const *s1, char const *s2, char *t)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		t[i] = s2[j];
		i++;
		j++;
	}
	return (t);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = 0;
	while (s1[s1len])
		s1len++;
	s2len = 0;
	while (s2[s2len])
		s2len++;
	if (!(t = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	t[s1len + s2len] = '\0';
	return (ft_fill_string(s1, s2, t));
}
