/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:40:58 by soopark           #+#    #+#             */
/*   Updated: 2022/04/02 13:40:43 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while ((i < dstsize) && (dst[i]))
			i++;
		while (src[j] && (i + j) < dstsize - 1)
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		if (i < dstsize)
			dst[i + j] = '\0';
	}
	return (i + src_len);
}
