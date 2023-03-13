/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:02:47 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 14:45:18 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_space_line(char *line)
{
	while (*line)
	{
		if (!(*line == ' ' || (*line >= 9 && *line <= 13)))
			return (0);
		line++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	if (!ft_strncmp(line, "\n", 1) || is_space_line(line))
		return (1);
	else
		return (0);
}

void	skip_line(int fd, char **line)
{
	*line = get_next_line(fd);
	if (!(*line))
		error(0);
	while ((*line) && is_empty_line(*line))
	{
		free(*line);
		*line = get_next_line(fd);
	}
}
