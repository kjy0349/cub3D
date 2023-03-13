/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:32:01 by jeykim            #+#    #+#             */
/*   Updated: 2023/03/13 16:22:21 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	draw_fl_ce(t_info *info)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT / 2)
		{
			info->mlx->screen[y][x] = info->cub->ce;
			info->mlx->screen[HEIGHT - y - 1][x] = info->cub->fl;
		}
	}
}

#include <stdio.h>
void	draw_line(t_info *info, t_wall w, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * PIXEL / w.line_h;
	tex_pos = (w.draw_start - HEIGHT / 2 + w.line_h / 2) * step;
	i = w.draw_start;
	while (i <= w.draw_end)
	{
		tex_y = (int)tex_pos & (PIXEL - 1);
		tex_pos += step;
		color = info->mlx->texture[w.side][PIXEL * tex_y + w.tex_x];
		info->mlx->screen[i][x] = color;
		i++;
	}
}

void	draw(t_info *i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			i->mlx->img.data[y * WIDTH + x] = i->mlx->screen[y][x];
	}
	mlx_put_image_to_window(i->mlx->ptr, i->mlx->win, i->mlx->img.img, 0, 0);
}

int	draw_screen(t_info *info)
{
	int		x;
	t_ray	r;
	t_wall	w;

	draw_fl_ce(info);
	x = -1;
	while (++x < WIDTH)
	{
		calc_ray(info->vec, &r, x);
		dda(&r, info->cub);
		calc_wall(info->vec, &r, &w);
		draw_line(info, w, x);
	}
	draw(info);
	return (0);
}
