/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:31:39 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/15 20:45:17 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_limits(int num, int digt, int sign)
{
	if (num > (2147483647 - (digt - '0')) / 10)
	{
		if (sign == 1)
			return (2147483647);
		return (-2147483648)
	}
}
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		check_limits(res, nptr[i], sign);
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
