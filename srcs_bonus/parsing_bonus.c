/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:42 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 14:45:18 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <fcntl.h>

void	check_mapfile(char *file, int *fd)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || file[len - 4] != '.' || file[len - 3] != 'c'\
		|| file[len - 2] != 'u' || file[len - 1] != 'b')
		error("invalid file name");
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		error("fail to open file");
}

void	parsing(char *file, t_info *info)
{
	int	fd;

	check_mapfile(file, &fd);
	parsing_texture(fd, info->cub);
	parsing_map(fd, info);
	close(fd);
}
