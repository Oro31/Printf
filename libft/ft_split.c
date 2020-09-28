/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:38:08 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 00:38:21 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fillwords(char const *s, char **t, char c)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	j = 0;
	if (s[0] == '\0')
		t[0] = NULL;
	while (*(s + i))
	{
		if (s[i] != c)
		{
			t[n][j] = s[i];
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				n++;
				j = 0;
			}
		}
		i++;
	}
	return (t);
}

static char	**ft_wordalloc(char const *s, char c, char **t, size_t n)
{
	int	nbl;
	int	i;

	i = 0;
	nbl = 0;
	while (s[i])
	{
		if (*(s + i) != c)
			nbl++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (!(t[n] = malloc(sizeof(char) * (nbl + 1))))
			{
				while (--n >= 0)
					free(t[n]);
				return (NULL);
			}
			t[n][nbl] = '\0';
			nbl = 0;
			n++;
		}
		i++;
	}
	return (ft_fillwords(s, t, c));
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	nbm;
	char	**t;

	if (s == NULL)
		return (NULL);
	nbm = 0;
	i = 0;
	while (*(s + i))
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbm++;
		i++;
	}
	if (!(t = malloc(sizeof(char *) * (nbm + 1))))
		return (NULL);
	t[nbm] = NULL;
	t = ft_wordalloc(s, c, t, 0);
	return (t);
}
