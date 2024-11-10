/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:33:37 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/10 21:35:01 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;

	i = 0;
	ptr1 = (unsigned char *)s;
	while (i < n)
	{
		ptr1[i] = 0;
		i++;
	}
}
