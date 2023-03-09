/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:52:35 by soopark           #+#    #+#             */
/*   Updated: 2022/04/06 18:47:43 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pre_order(char *s1, char *set)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				cnt++;
				break ;
			}
			if (set[j + 1] == '\0')
				return (cnt);
			j++;
		}
		i++;
	}
	return (cnt);
}

static int	post_order(char *s1, char *set)
{
	size_t	len;
	int		i;
	int		cnt;

	cnt = 0;
	len = ft_strlen(s1);
	if (len)
	{
		while (--len)
		{
			i = 0;
			while (set[i])
			{
				if (s1[len] == set[i])
				{
					cnt++;
					break ;
				}
				if (set[i + 1] == '\0')
					return (cnt);
				i++;
			}
		}
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		pre_cnt;
	int		post_cnt;
	size_t	len;
	char	*arr;

	if (!s1 || !set)
		return (NULL);
	pre_cnt = pre_order((char *)s1, (char *)set);
	post_cnt = post_order((char *)s1, (char *)set);
	len = ft_strlen(s1);
	if ((int) len == pre_cnt)
	{
		arr = (char *)malloc(sizeof(char));
		if (arr == NULL)
			return (NULL);
		arr[0] = '\0';
	}
	else
	{
		arr = (char *)malloc(sizeof(char) * (len - (pre_cnt + post_cnt) + 1));
		if (arr == NULL)
			return (NULL);
	}
	ft_strlcpy(arr, s1 + pre_cnt, len - (pre_cnt + post_cnt) + 1);
	return (arr);
}
