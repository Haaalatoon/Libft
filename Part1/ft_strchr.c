/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:15:56 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/18 12:15:58 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*found;

	found = (char *)s;
	while (*found)
	{
		if (*found == (unsigned char)c)
			return (found);
		found++;
	}
	if (c == '\0')
		return (found);
	return (NULL);
}
