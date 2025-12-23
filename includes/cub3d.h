/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:08:33 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/23 17:02:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_rc_ctx
{
	double		x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		draw_start;
	double		draw_end;
	int			map_x;
	int			map_y;
	double		step_x;
	double		step_y;
	int			line_height;
	int			side;
}				t_rc_ctx;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct wall_texture
{
	int			x;
	int			y;
	double		position;
	int			offset;
	t_img		*img;
}				t_wall_texture;

typedef struct s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_img		*north_img;
	t_img		*south_img;
	t_img		*west_img;
	t_img		*east_img;
}				t_textures;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	char		orientation;
	double		dir_x;
	double		dir_y;
	double		cam_x;
	double		cam_y;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			rotate_left;
	int			rotate_right;
	int			moove_forward;
	int			moove_backward;
	int			moove_left;
	int			moove_right;
	t_textures	textures;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_player	player;
	t_img		*img;
}				t_game;

//----------------mlx----------------//

//---mlx_utils.c---//
int			handle_close(void *game_ptr);
void		free_mlx(t_game *game);
void		mlx_inits(t_game *game);
void		img_init(t_img *img, t_game *game, char *filename);

//---player_movements.c---//
void		rotate_left_or_right(t_game *game, double angle);
void		moove_forward_backward_left_or_right(t_game *game, double ms);
void		update_pos_n_dir(t_game *game);

//---keys_handling.c---//
int			moovement_keys(int keycode, t_game *game);
int			handle_key_release(int keycode, void *game_ptr);
int			handle_key(int keycode, void *game_ptr);

//---render.c---//
void		put_pixel(t_img *img, int x, int y, int color);
int			create_color(int r, int g, int b);
void		render_floor_n_ceiling(t_game *game);
int			render_frame(void *game_ptr);

//--wall_drawing.c---//
void		draw_wall_color(t_game *game, t_rc_ctx *rc_ctx, int wall_color);
void		draw_loop(t_game *game, t_rc_ctx *rc_ctx,
				t_wall_texture *wall_texture);
void		vertical_wall_math(t_game *game, t_rc_ctx *rc_ctx,
				t_wall_texture *wall_texture);
void		horizontal_wall_math(t_game *game, t_rc_ctx *rc_ctx,
				t_wall_texture *wall_texture);
void		draw_wall_texture(t_game *game, t_rc_ctx *rc_ctx);

//---ray_casting.c---//
int			digital_differential_analysis_ops(t_player *player,
				t_rc_ctx *rc_ctx);
void		project_ray_until_wall(t_game *game, t_rc_ctx *rc_ctx);
void		ray_casting(t_game *game);

//---game_utils.c---//
int			init_player_vectors(t_game *game);
void		free_textures_imgs(t_game *game);
void		init_textures_imgs(t_game *game);

//----------------parsing----------------//

//---parse_elements.c---//
int			parse_texture(char *line, char **texture);
int			parse_color(char *line, t_color *color);

//---parse-file---//
int			is_map_char(char c);
int			is_map_line(char *line, t_game *game, int fd);
int			parse_file(char *filename, t_game *game);

//---parse_identifiers.c---//
void		parse_element(char *line, t_game *game, int fd);

//---parse_map.c---///
int			read_map(int fd, char *first_line, t_game *game, char *filename);

//---parse_utils.c---//
int			is_empty_line(char *line);
char		*skip_identifiers(char *line);
int			free_temp(char **temp, int i);

//---validate_file.c---//
int			validate_extension(char *filename);
int			check_all_elements_parsed(t_game *game);

//---validate_map.c---//
int			validate_map(t_game *game);

//---validate_texture---//
int			validate_textures(t_game *game);

//----------------utils----------------//

//---error.c---//
void		print_error(char *msg);
void		exit_error(char *msg, t_game *game, char *line, int fd);
void		free_game(t_game *game);

#endif
