/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:16:00 by soopark           #+#    #+#             */
/*   Updated: 2023/03/09 15:14:49 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/mlx/mlx.h"
# include "../libs/Libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

# define HEIGHT 	480
# define WIDTH 		640
# define PIXEL		16

# define KEY_PRESS	2
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_R 		124
# define KEY_L		123
# define KEY_ESC	53

# define DISTROY	17
# define KEY_ESC	53

typedef struct s_img {
	void	*img;
	int		bpp;
	int		size_l;
	int		endian;
	int		*data;
}	t_img;

typedef struct s_cub {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fl;
	int		ce;
	char	**map;
	int		h;
	int		w;
}	t_cub;

typedef struct s_mlx {
	void	*ptr;
	void	*win;
	int		**screen;
	int		*texture[4];
	t_img	img;
}	t_mlx;

typedef struct s_vec {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_vec;

typedef struct s_parse {
	int		is_p;
	int		is_e;
	char	*line;
	char	*full_line;
}	t_parse;

typedef struct s_info {
	struct s_cub	*cub;
	struct s_mlx	*mlx;
	struct s_vec	*vec;
}	t_info;

/*main*/
void	error(char *str);

/*init*/
void	init_cub(t_cub *cub);
void	init_vec(t_vec *s_vec, char c, int x, int y);
void	init_mlx(t_info *info);

/*parsing*/
void	parsing(char *file, t_info *info);
void	parsing_texture(int fd, t_cub *cub);
void	parsing_map(int fd, t_info *info);
void	put_rgb(int *texture, char *value);

/*free*/
void	free_split(char **str);

/*parsing utils*/
void	skip_line(int fd, char **line);
int		is_empty_line(char *line);

/*draw utils*/
void	my_xpm_to_img(t_mlx *m, int dir, char *wall);

#endif