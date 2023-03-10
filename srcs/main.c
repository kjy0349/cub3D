/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:15:30 by soopark           #+#    #+#             */
/*   Updated: 2023/03/10 22:02:23 by soopark          ###   ########.fr       */
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
	// mlx_hook(info->mlx->win, DESTROY, 0, &close, info->mlx);
	mlx_loop(info->mlx->ptr);
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
