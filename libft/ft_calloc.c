/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:20:13 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 03:31:24 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	char	*t;
	size_t	i;

	i = 0;
	if (!(s = malloc(size * nmemb)))
		return (NULL);
	t = (char *)s;
	while (i < size * nmemb)
	{
		t[i] = '\0';
		i++;
	}
	if (size * nmemb == 0)
		t[0] = '\0';
	return (s);
}
