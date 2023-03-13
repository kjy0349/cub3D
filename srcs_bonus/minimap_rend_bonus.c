/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rend_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:14:56 by jeykim            #+#    #+#             */
/*   Updated: 2023/03/13 15:25:01 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	make_minimap(t_mlx *m, int y, int x, char elem)
{
	int	color;
	int	i;
	int	j;

	if (elem == ' ')
		return ;
	if (elem == '1')
		color = 0x000000;
	if (elem == '0')
		color = 0xffffff;
	if (elem == 'p')
		color = 0x00ff00;
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			m->screen[(y *  5) + i][(x * 5) + j] = color;
	}
}

void	draw_minimap(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < info->cub->h)
	{
		x = -1;
		while (++x < info->cub->w)
		{
			if (y == (int)info->vec->pos_y && x == (int)info->vec->pos_x)
				make_minimap(info->mlx, y, x, 'p');
			else
				make_minimap(info->mlx, y, x, info->cub->map[y][x]);
		}
	}
}