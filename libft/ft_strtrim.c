/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:57:27 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 01:23:45 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trim_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	return (i);
}

static int		ft_nb_alloc(size_t slen, size_t i)
{
	if (slen <= i)
		return (1);
	else
		return (slen - i + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*t;
	size_t	i;
	size_t	n;
	size_t	slen;

	if (s1 == NULL || set == NULL)
		return (NULL);
	slen = 0;
	while (s1[slen])
		slen++;
	i = ft_trim_start(s1, set);
	n = 0;
	while (ft_is_set(s1[slen - 1], set) && slen > 1)
		slen--;
	if (!(t = malloc(sizeof(char) * ft_nb_alloc(slen, i))))
		return (NULL);
	while (i < slen)
	{
		t[n] = s1[i];
		n++;
		i++;
	}
	t[n] = '\0';
	return (t);
}
