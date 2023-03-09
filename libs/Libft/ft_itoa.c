/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:23:27 by soopark           #+#    #+#             */
/*   Updated: 2022/04/03 11:48:03 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digit(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
		digit++;
	while (n)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

static void	put_nbr(char *array, long n, int digit)
{
	while (n)
	{
		array[--digit] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		digit;
	char	*array;

	digit = num_digit(n);
	if (digit == 0)
	{
		array = (char *)malloc(sizeof(char) * 2);
		array[0] = '0';
		array[1] = '\0';
		return (array);
	}
	array = (char *)malloc(sizeof(char) * (digit + 1));
	if (array == NULL)
		return (NULL);
	array[digit] = '\0';
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		array[0] = '-';
	}
	put_nbr(array, nb, digit);
	return (array);
}
