/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:11:09 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 14:44:12 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

void	xpm_to_img(t_mlx *m, int dir, char *wall)
{
	t_img	img;
	int		x;
	int		y;
	int		w;
	int		h;

	img.img = mlx_xpm_file_to_image(m->ptr, wall, &w, &h);
	if (!img.img)
		error("invalid texture");
	img.data = (int *)mlx_get_data_addr(img.img, \
		&img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			m->texture[dir][w * y + x] = img.data[w * y + x];
	}
	mlx_destroy_image(m->ptr, img.img);
}

void	calc_dis(t_vec *v, t_ray *r, t_wall *w)
{
	if (r->side == 0 || r->side == 1)
	{
		w->wall_dist = (r->map_x - v->pos_x + \
			(1 - r->step_x) / 2) / r->raydir_x;
		w->wall_x = v->pos_y + w->wall_dist * r->raydir_y;
	}
	else
	{
		w->wall_dist = (r->map_y - v->pos_y + \
			(1 - r->step_y) / 2) / r->raydir_y;
		w->wall_x = v->pos_x + w->wall_dist * r->raydir_x;
	}
	w->wall_x -= floor(w->wall_x);
}

void	calc_wall(t_vec *v, t_ray *r, t_wall *w)
{
	calc_dis(v, r, w);
	w->line_h = (HEIGHT / w->wall_dist);
	w->side = r->side;
	w->tex_x = (int)(w->wall_x * (double)PIXEL);
	if (((r->side == 0) || (r->side == 1)) && r->raydir_x < 0)
		w->tex_x = PIXEL - w->tex_x - 1;
	if (((r->side == 2) || (r->side == 3)) && r->raydir_y > 0)
		w->tex_x = PIXEL - w->tex_x - 1;
	w->draw_start = -w->line_h / 2 + HEIGHT / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_h / 2 + HEIGHT / 2;
	if (w->draw_end >= HEIGHT)
		w->draw_end = HEIGHT - 1;
}
