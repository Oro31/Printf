/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:37:05 by rvalton           #+#    #+#             */
/*   Updated: 2020/02/09 01:14:25 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	slen;

	if (s != NULL)
	{
		if (fd != -1)
		{
			slen = 0;
			while (s[slen])
				slen++;
			write(fd, s, slen);
			write(fd, "\n", 1);
		}
	}
}
