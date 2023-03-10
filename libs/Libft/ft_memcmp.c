/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:55:44 by soopark           #+#    #+#             */
/*   Updated: 2022/04/02 14:24:53 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n > 0)
	{
		while (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i) && \
				i < n - 1)
		{
			i++;
		}
	}
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
