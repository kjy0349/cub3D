/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:16:00 by soopark           #+#    #+#             */
/*   Updated: 2023/03/13 17:08:42 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libs/mlx/mlx.h"
# include "../libs/Libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

# define HEIGHT 	480
# define WIDTH 		640
# define PIXEL		64

# define KEY_PRESS	2
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_R 		124
# define KEY_L		123
# define KEY_ESC	53

# define DESTROY	17
# define KEY_ESC	53
# define MOUSEMOVE	6

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

typedef struct s_ray {
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_wall {
	double	wall_x;
	int		step;
	int		side;
	int		tex_x;
	int		line_h;
	int		draw_start;
	int		draw_end;
	double	wall_dist;
}	t_wall;

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
int		end(t_mlx *mlx);

/*init*/
void	init_cub(t_cub *cub);
void	init_vec(t_vec *s_vec, char c, int x, int y);
void	init_screen(t_mlx *mlx);
void	init_texture(t_mlx *mlx, t_cub *cub);

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
void	xpm_to_img(t_mlx *m, int dir, char *wall);

/*draw*/
int		draw_screen(t_info *info);
void	calc_wall(t_vec *v, t_ray *r, t_wall *w);
void	draw_minimap(t_info *info);

/*raycasting*/
void	dda(t_ray *r, t_cub *c);
void	calc_ray(t_vec *v, t_ray *r, int x);

/*move*/
int		key_press(int keycode, t_info *info);
int		mouse_move(int x, int y, t_info *info);

#endif