/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:46:30 by soopark           #+#    #+#             */
/*   Updated: 2022/04/10 14:04:03 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_white_space(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static int	check_long(char next, long prev, int negative)
{
	if ((prev * 10 + next - '0') / 10 != prev)
	{
		if (negative == -1)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		negative;
	int		i;

	res = 0;
	i = 0;
	negative = 1;
	while (check_white_space(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_long(str[i], res, negative) == 1)
			res = res * 10 + str[i] - '0';
		else
			return (check_long(str[i], res, negative));
		i++;
	}
	return ((int)(res * negative));
}
