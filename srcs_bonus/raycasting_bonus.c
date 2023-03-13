/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:17:26 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 14:45:18 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

void	init_ray(t_vec *v, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double) WIDTH - 1;
	r->raydir_x = v->dir_x + v->plane_x * r->camera_x;
	r->raydir_y = v->dir_y + v->plane_y * r->camera_x;
	r->map_x = (int) v->pos_x;
	r->map_y = (int) v->pos_y;
	r->deltadist_x = fabs(1 / r->raydir_x);
	r->deltadist_y = fabs(1 / r->raydir_y);
	r->hit = 0;
}

void	calc_ray(t_vec *v, t_ray *r, int x)
{
	init_ray(v, r, x);
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (v->pos_x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - v->pos_x) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (v->pos_y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - v->pos_y) * r->deltadist_y;
	}
}

void	dda(t_ray *r, t_cub *c)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			if (r->step_x == 1)
				r->side = 0;
			else
				r->side = 1;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			if (r->step_y == 1)
				r->side = 2;
			else
				r->side = 3;
		}
		if (c->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}
