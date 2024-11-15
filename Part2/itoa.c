/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:56:07 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/15 21:58:21 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	abs_value(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

char	*case_0(void)
{
	char	*number;

	number = (char *)malloc(2 * sizeof(char));
	if (!number)
		return (NULL);
	ft_strlcpy(number, "0", 2);
	return (number);
}

char	*case_int_min(void)
{
	char	*number;

	number = (char *)malloc(12 * sizeof(char));
	if (!number)
		return (NULL);
	ft_strlcpy(number, "-2147483648", 12);
	return (number);
}

char	*fill_number(char *number, unsigned int num, int size)
{
	int	i;

	i = size;
	while (num)
	{
		number[--i] = num % 10 + '0';
		num = num / 10;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char			*number;
	int				count;
	int				size;
	unsigned int	num;

	count = 0;
	if (n == 0)
		return (case_0());
	if (n == -2147483648)
		return (case_INT_MIN());
	num = abs_value(n);
	while (num)
	{
		count++;
		num = num / 10;
	}
	size = count + (n < 0);
	number = (char *)malloc((size + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[size] = '\0';
	if (n < 0)
		number[0] = '-';
	num = abs_value(n);
	fill_number(number, num, size);
	return (number);
}
