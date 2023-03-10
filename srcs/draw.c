/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:32:01 by jeykim            #+#    #+#             */
/*   Updated: 2023/03/10 18:57:45 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	draw_screen(t_info *info)
{
// 바닥, 벽 먼저 그리고
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
// 끝

// 레이 계산 시작
	x = -1;
	while (++x < WIDTH)
	{
		t_vec *vec = info->vec;
		double	cameraX = 2 * x / (double)WIDTH - 1;
		double	rayDirX = vec->dir_x + vec->plane_x * cameraX;
		double	rayDirY = vec->dir_y + vec->plane_y * cameraX;

		int	mapX = (int)vec->pos_x;
		int	mapY = (int)vec->pos_y;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (vec->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - vec->pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (vec->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - vec->pos_y) * deltaDistY;
		}

		t_cub *cub = info->cub;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				if (stepX == 1)
					side = 0;
				else
					side = 1;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				if (stepY == 1)
					side = 2;
				else
					side = 3;
			}
			if (cub->map[mapY][mapX] == '1')
				hit = 1;
		}
		// 레이 dda 끝
		// 벽 충돌 방향에 따른 WallDist 계산
		double	wall_x;
		double	perpWallDist;

		if (side == 0 || side == 1)
		{
			perpWallDist = (mapX - vec->pos_x + (1 - stepX) / 2) / rayDirX;
			wall_x = vec->pos_y + perpWallDist + rayDirY;
		}
		else
		{
			perpWallDist = (mapY - vec->pos_y + (1 - stepY) / 2) / rayDirY;
			wall_x = vec->pos_x + perpWallDist + rayDirX;
		}
		wall_x -= floor(wall_x);
		// WallDist 끝
		// 벽 높이 계산
		int	lineHeight = (int)(HEIGHT / perpWallDist);
		int	drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		int	texX = (int)(wall_x * (double)PIXEL);
		if (((side == 0) || (side == 1)) && rayDirX < 0)
			texX = PIXEL - texX - 1;
		if (((side == 2) || (side == 3)) && rayDirY > 0)
			texX = PIXEL - texX - 1;
		// 벽 높이 계산 끝 calcWall

		// 텍스처 적용
		double	step = 1.0 * PIXEL / lineHeight;
		double	texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
		int i = drawStart;
		while (i <= drawEnd)
		{
			int	texY = (int)texPos & (PIXEL - 1);
			texPos += step;
			int color = info->mlx->texture[side][PIXEL * texY + texX];
			info->mlx->screen[i][x] = color;
			i++;
		}
		// 텍스처 적용 끝 map_line
		// 그리기!
		int	x;
		int	y;

		y = -1;
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				info->mlx->img.data[y * WIDTH + x] = info->mlx->screen[y][x];
		}
		mlx_put_image_to_window(info->mlx->ptr, info->mlx->win, info->mlx->img.img, 0, 0);
		// 그리기 끝
	}

	return (0);
}