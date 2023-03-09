/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:55 by soopark           #+#    #+#             */
/*   Updated: 2022/09/21 15:56:12 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	int			fd;
	char		rb_arr[BUFFER_SIZE];
	ssize_t		rb_size;
	size_t		rb_pos;
	char		*str;
	size_t		s_size;
	size_t		s_pos;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
t_file	*check_file(int fd, t_file **file);
t_file	*init_file(int fd, t_file **file);
void	copy_to_str(t_file *file);
void	ft_realloc(t_file *file);
char	*free_file(t_file **file);

#endif
