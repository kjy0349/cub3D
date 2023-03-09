/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:49:48 by soopark           #+#    #+#             */
/*   Updated: 2023/03/09 15:20:16 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_texture(char **texture, char *value)
{
	*texture = ft_substr(value, 0, ft_strlen(value) - 1);
	if (!(*texture))
		error(0);
}

void	set_texture(char *key, char *value, t_cub *cub)
{
	size_t	len;

	len = ft_strlen(key);
	if (ft_strncmp(key, "NO", len) == 0 && cub->no == NULL)
		put_texture(&cub->no, value);
	else if (ft_strncmp(key, "SO", len) == 0 && cub->so == NULL)
		put_texture(&cub->so, value);
	else if (ft_strncmp(key, "WE", len) == 0 && cub->we == NULL)
		put_texture(&cub->we, value);
	else if (ft_strncmp(key, "EA", len) == 0 && cub->ea == NULL)
		put_texture(&cub->ea, value);
	else if (ft_strncmp(key, "F", len) == 0 && cub->fl == -1)
		put_rgb(&cub->fl, value);
	else if (ft_strncmp(key, "C", len) == 0 && cub->ce == -1)
		put_rgb(&cub->ce, value);
	else
		error("invalid texture");
}

int	check_texture(int fd, t_cub *cub)
{
	char	*line;
	char	**s_line;
	int		err;

	err = 0;
	s_line = NULL;
	line = get_next_line(fd);
	if (!line)
		error(0);
	if (!is_empty_line(line))
	{
		s_line = ft_split(line, ' ');
		if (!s_line)
			error(0);
		set_texture(s_line[0], s_line[1], cub);
	}
	free(line);
	free_split(s_line);
	return (err);
}

void	parsing_texture(int fd, t_cub *cub)
{
	init_cub(cub);
	while (cub->no == NULL || cub->so == NULL || cub->we == NULL \
		|| cub->ea == NULL || cub->fl == -1 || cub->ce == -1)
		check_texture(fd, cub);
}
