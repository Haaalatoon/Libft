/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:19:07 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/10 22:19:08 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*found;

	found = (char *)s;
	while (*found)
	{
		if (*found == c)
			return (found);
		found++;
	}
	if (c == '\0')
		return (found);
	return (NULL);
}
