/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:03:03 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/15 21:04:02 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*found;
	size_t			i;

	i = 0;
	found = (unsigned char *)s;
	while (i < n)
	{
		if (found[i] == (unsigned char)c)
			return ((void *)(found + i));
		i++;
	}
	return (NULL);
}
