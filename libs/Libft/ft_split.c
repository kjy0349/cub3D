/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:16:21 by soopark           #+#    #+#             */
/*   Updated: 2022/04/07 16:41:23 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char ***p_arr)
{
	int	i;

	i = 0;
	while ((*p_arr)[i])
	{
		free((*p_arr)[i]);
		(*p_arr)[i] = NULL;
		i++;
	}
	free(*p_arr);
	return (NULL);
}

static int	ft_size(char *str, char c)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] && str[i] == c)
			i++;
		while (str[i + j] && str[i + j] != c)
			j++;
		if (j != 0)
			size++;
		i = i + j;
	}
	return (size);
}

static char	*ft_split_str(char *p_arr, char *str, int idx, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		p_arr[i] = str[idx + i];
		i++;
	}
	p_arr[i] = '\0';
	return (p_arr);
}

static char	**ft_split_size(char **p_arr, char *str, char c)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		s = 0;
		while (str[i + s] != '\0' && str[i + s] != c)
			s++;
		if (s > 0)
		{
			p_arr[j] = (char *)malloc(sizeof(char) * (s + 1));
			if (p_arr[j] == NULL)
				return (free_all(&p_arr));
			p_arr[j] = ft_split_str(p_arr[j], str, i, s);
			j++;
		}
		i += s;
	}
	return (p_arr);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**p_arr;

	if (!s)
		return (NULL);
	size = ft_size((char *)s, c);
	p_arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (p_arr == NULL)
		return (NULL);
	p_arr[size] = 0;
	p_arr = ft_split_size(p_arr, (char *)s, c);
	return (p_arr);
}
