/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:49:43 by soopark           #+#    #+#             */
/*   Updated: 2022/04/07 15:12:46 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_length(size_t s_len, int start, size_t len)
{
	if (start + len > s_len)
		return (s_len - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	s_idx;
	size_t	array_idx;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		array = (char *)malloc(sizeof(char));
		array[0] = 0x00;
		return (array);
	}
	array = malloc(sizeof(char) * (find_length(ft_strlen(s), start, len) + 1));
	if (array == NULL)
		return (0);
	s_idx = start;
	array_idx = 0;
	while (s[s_idx] && array_idx < len)
	{
		array[array_idx] = s[s_idx];
		array_idx++;
		s_idx++;
	}
	array[array_idx] = '\0';
	return (array);
}
