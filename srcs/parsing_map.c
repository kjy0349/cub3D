/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:10:34 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 15:48:56 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_close(int y, char **map, t_cub *tex)
{
	int	x;

	x = -1;
	while (++x < tex->w)
	{
		if (map[y][x] == '0' && (\
		y == 0 || y == tex->h - 1 || x == 0 || x == tex->w - 1 \
		|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ' \
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			error("Invaild map.");
	}	
}

void	make_lines(char **lines, int w)
{
	int		size;
	char	*fill;
	char	*tmp;

	size = w - (int)ft_strlen(*lines);
	if (size > 0)
	{
		fill = ft_calloc(sizeof(char), size + 1);
		if (!fill)
			error(0);
		ft_memset(fill, ' ', size);
		tmp = ft_strjoin(*lines, fill);
		free(*lines);
		*lines = tmp;
		if (!*lines)
			error(0);
		free(fill);
	}
}

void	set_map(char *full_line, t_cub *texture)
{
	int		y;
	char	**map;

	y = -1;
	map = ft_split(full_line, '\n');
	free(full_line);
	if (!map)
		error(0);
	while (++y < texture->h)
		make_lines(&map[y], texture->w);
	y = -1;
	while (++y < texture->h)
		check_close(y, map, texture);
	texture->map = map;
}

int	check_elem(char *line, int *is_p, t_info *info)
{
	int	x;

	x = -1;
	while (line[++x])
	{
		if (!(*is_p) && ft_strchr("NSEW", line[x]))
		{
			init_vec(info->vec, line[x], x, info->cub->h);
			*is_p = 1;
			line[x] = '0';
			continue ;
		}
		if (!ft_strchr("10 \n", line[x]))
			return (1);
	}
	if (--x > info->cub->w)
		info->cub->w = x;
	info->cub->h++;
	return (0);
}

void	parsing_map(int fd, t_info *info)
{
	t_parse	p;
	char	*tmp;

	ft_bzero(&p, sizeof(t_parse));
	skip_line(fd, &p.line);
	while (p.line)
	{
		if (!is_empty_line(p.line))
		{
			if (p.is_e || check_elem(p.line, &p.is_p, info))
				error("Invaild map.");
			tmp = ft_strjoin(p.full_line, p.line);
			free(p.full_line);
			p.full_line = tmp;
			if (!p.full_line)
				error(0);
		}
		else
			p.is_e = 1;
		free(p.line);
		p.line = get_next_line(fd);
	}
	if (!p.is_p)
		error("Player coordinate not found.");
	set_map(p.full_line, info->cub);
}
