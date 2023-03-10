/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:52:56 by soopark           #+#    #+#             */
/*   Updated: 2023/03/10 11:31:45 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->ea = NULL;
	cub->we = NULL;
	cub->map = NULL;
	cub->fl = -1;
	cub->ce = -1;
	cub->h = 0;
	cub->w = 0;
}

void	init_vec(t_vec *vec, char c, int x, int y)
{
	vec->pos_x = (double)x + 0.5;
	vec->pos_y = (double)y + 0.5;
	vec->dir_x = 1.0;
	vec->dir_y = 1.0;
	vec->plane_x = 0.66;
	vec->plane_y = 0.66;
	if (c == 'N' || c == 'S')
	{
		vec->dir_x = 0;
		vec->plane_y = 0;
		if (c == 'N')
			vec->dir_y *= -1;
		else
			vec->plane_x *= -1;
	}
	if (c == 'E' || c == 'W')
	{
		vec->dir_y = 0;
		vec->plane_x = 0;
		if (c == 'W')
		{
			vec->dir_x *= -1;
			vec->plane_y *= -1;
		}
	}
}

void	init_texture(t_mlx *mlx, t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx->texture[i] = malloc(sizeof(int) * PIXEL * PIXEL);
		if (mlx->texture[i] == NULL)
			error(0);
		ft_bzero(mlx->texture[i], sizeof(int) * PIXEL * PIXEL);
	}
	xpm_to_img(mlx, 0, cub->we);
	xpm_to_img(mlx, 1, cub->ea);
	xpm_to_img(mlx, 2, cub->no);
	xpm_to_img(mlx, 3, cub->so);
	mlx->img.img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
		&mlx->img.size_l, &mlx->img.endian);
}

void	init_screen(t_mlx *mlx)
{
	int	i;

	mlx->screen = malloc(sizeof(int *) * HEIGHT);
	if (mlx->screen == NULL)
		error(0);
	i = -1;
	while (++i < HEIGHT)
	{
		mlx->screen[i] = malloc(sizeof(int) * WIDTH);
		if (mlx->screen[i] == NULL)
			error(0);
		ft_bzero(mlx->screen[i], sizeof(int) * WIDTH);
	}
}

void	init_mlx(t_info *info)
{
	init_screen(info->mlx);
	init_texture(info->mlx, info->cub);
}
