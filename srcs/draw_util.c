/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:11:09 by soopark           #+#    #+#             */
/*   Updated: 2023/03/09 15:24:15 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_xpm_to_img(t_mlx *m, int dir, char *wall)
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