/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:29:13 by jeykim            #+#    #+#             */
/*   Updated: 2023/03/10 18:55:32 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_vec *vec, int dir)
{
	double	rot;

	rot = vec->rot_speed / 10 * dir;
	vec->dir_x = vec->dir_x * cos(rot) - vec->dir_y * sin(rot);
	vec->dir_y = vec->dir_x * sin(rot) - vec->dir_y * cos(rot);
	vec->plane_x = vec->plane_x * cos(rot) - vec->plane_y * sin(rot);
	vec->plane_y = vec->plane_x * cos(rot) - vec->plane_y * sin(rot);
}

static void	move_fb(t_vec *vec, t_cub *cub, double dir)
{
	double	next_x;
	double	next_y;

	next_x = vec->pos_x + vec->dir_x * vec->move_speed / 10 * dir;
	next_y = vec->pos_y + vec->dir_y * vec->move_speed / 10 * dir;
	if (cub->map[(int)vec->pos_y][(int)next_x] == '0')
		vec->pos_x = next_x;
	if (cub->map[(int)next_y][(int)vec->pos_x] == '0')
		vec->pos_y = next_y;
}

static void	move_lr(t_vec *vec, t_cub *cub, double dir)
{
	double	next_x;
	double	next_y;

	next_x = vec->pos_x + vec->plane_x * vec->move_speed / 10 * dir;
	next_y = vec->pos_y + vec->plane_y * vec->move_speed / 10 * dir;
	if (cub->map[(int)vec->pos_y][(int)next_x] == '0')
		vec->pos_x = next_x;
	if (cub->map[(int)next_y][(int)vec->pos_x] == '0')
		vec->pos_y = next_y;
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		move_fb(info->vec, info->cub, 1);
	if (keycode == KEY_S)
		move_fb(info->vec, info->cub, -1);
	if (keycode == KEY_A)
		move_lr(info->vec, info->cub, -1);
	if (keycode == KEY_D)
		move_lr(info->vec, info->cub, 1);
	if (keycode == KEY_R)
		rotate(info->vec, 1);
	if (keycode == KEY_L)
		rotate(info->vec, -1);
	return (0);
}