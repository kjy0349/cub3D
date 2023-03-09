/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:11:07 by soopark           #+#    #+#             */
/*   Updated: 2022/07/14 00:25:05 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*check_file(int fd, t_file **file)
{
	t_file	*init;

	if ((*file)->fd == fd)
		return (*file);
	init = *file;
	*file = (*file)->next;
	while (*file != init)
	{
		if ((*file)->fd == fd)
			return (*file);
		*file = (*file)->next;
	}
	return (NULL);
}

t_file	*init_file(int fd, t_file **file)
{
	t_file	*new_file;

	new_file = (t_file *)malloc(sizeof(t_file));
	if (new_file == NULL)
		return (NULL);
	new_file->fd = fd;
	new_file->rb_size = 0;
	new_file->next = new_file;
	if (*file == NULL)
		return (new_file);
	new_file->next = (*file)->next;
	(*file)->next = new_file;
	*file = new_file;
	return (*file);
}

void	copy_to_str(t_file *file)
{
	while (1)
	{
		if (file->rb_size == 0)
		{
			file->rb_size = read(file->fd, file->rb_arr, BUFFER_SIZE);
			if (file->rb_size <= 0)
				return ;
			file->rb_pos = 0;
		}
		if (file->s_pos == 0 || file->s_pos + file->rb_size >= file->s_size)
			ft_realloc(file);
		if (file->str == NULL)
			return ;
		file->str[file->s_pos++] = file->rb_arr[file->rb_pos++];
		file->rb_size--;
		if (file->rb_arr[file->rb_pos - 1] == '\n')
		{
			return ;
		}
	}
}

void	ft_realloc(t_file *file)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (file->s_pos == 0)
		file->s_size = BUFFER_SIZE;
	else
		file->s_size += BUFFER_SIZE;
	new_str = (char *)malloc(file->s_size);
	while (i < file->s_pos && new_str != NULL)
	{
		new_str[i] = file->str[i];
		i++;
	}
	free(file->str);
	file->str = new_str;
}

char	*free_file(t_file **file)
{
	t_file	*del_file;

	if (*file == (*file)->next)
	{
		free(*file);
		*file = NULL;
		return (NULL);
	}
	del_file = *file;
	*file = (*file)->next;
	while (del_file != (*file)->next)
		*file = (*file)->next;
	(*file)->next = del_file->next;
	free(del_file);
	del_file = NULL;
	return (NULL);
}
