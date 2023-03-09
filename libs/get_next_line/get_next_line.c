/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:57:17 by soopark           #+#    #+#             */
/*   Updated: 2022/07/07 15:39:26 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	*file = NULL;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (file == NULL || check_file(fd, &file) == NULL)
		file = init_file(fd, &file);
	if (file == NULL)
		return (NULL);
	file->s_pos = 0;
	file->str = NULL;
	copy_to_str(file);
	if (file->rb_size == -1 && file->s_pos > 0)
	{
		free(file->str);
		file->str = NULL;
	}
	if (file->str == NULL)
	{
		free_file(&file);
		return (NULL);
	}
	if (file->s_pos > 0)
		file->str[file->s_pos] = '\0';
	return (file->str);
}
