/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:16:00 by soopark           #+#    #+#             */
/*   Updated: 2022/04/10 14:27:31 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (size != 0 && (count * size) / size != count)
		return (NULL);
	array = (void *)malloc(sizeof(void) * (count * size));
	if (array == NULL)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}
