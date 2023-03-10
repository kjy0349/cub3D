/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:15:30 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 16:18:56 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	error(char *str)
{
	if (str)
		printf("Error : %s\n", str);
	else
		perror("Error\n");
	exit(1);
}

int	end(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

void	start(t_info *info)
{
	info->mlx->ptr = mlx_init();
	if (!info->mlx->ptr)
		error("fail to assign mlx");
	info->mlx->win = mlx_new_window(info->mlx->ptr, WIDTH, HEIGHT, "cub3D");
	if (!info->mlx->win)
		error("fail to assign mlx");
	init_screen(info->mlx);
	init_texture(info->mlx, info->cub);
	mlx_loop_hook(info->mlx->ptr, &draw_screen, info);
	mlx_hook(info->mlx->win, KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->mlx->win, DESTROY, 0, &end, info->mlx);
	mlx_loop(info->mlx->ptr);
}

void	checkd(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_cub	cub;
	t_mlx	mlx;
	t_vec	vec;

	if (argc != 2)
		error("bad arguments");
	info.cub = &cub;
	info.mlx = &mlx;
	info.vec = &vec;
	parsing(argv[1], &info);
	start(&info);
	return (0);
}
