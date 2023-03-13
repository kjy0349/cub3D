/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:20:33 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 14:45:18 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	calc_rgb(int color, int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	color <<= 8;
	return (color |= rgb);
}

void	put_rgb(int *texture, char *value)
{
	char	**split;
	int		color;
	int		i;

	i = -1;
	color = 0;
	if (value[ft_strlen(value) - 1] == '\n')
		value[ft_strlen(value) - 1] = '\0';
	split = ft_split(value, ',');
	if (!split)
		error(0);
	while (split[++i])
	{
		if (i < 3 && !check_isdigit(split[i]))
			break ;
		color = calc_rgb(color, ft_atoi(split[i]));
		if (color < 0)
			break ;
	}
	free_split(split);
	if (color < 0 || i != 3)
		error("invalid rgb");
	*texture = color;
}
