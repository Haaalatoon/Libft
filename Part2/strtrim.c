/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:11:27 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/16 00:06:37 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str_trim;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
	{
		str_trim = (char *)malloc(1 * sizeof(char));
		if (str_trim == NULL)
			return (NULL);
		str_trim[0] = '\0';
		return (str_trim);
	}
	str_trim = (char *)malloc(((end - start + 1) + 1) * sizeof(char));
	i = 0;
	while (start <= end)
		str_trim[i++] = s1[start++];
	str_trim[i] = '\0';
	return (str_trim);
}
