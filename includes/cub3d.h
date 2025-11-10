/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:08:33 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/10 16:12:50 by awaegaer         ###   ########.fr       */
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

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
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
	t_textures	textures;
	t_color		floor;
	t_color		ceilling;
	t_map		map;
	t_player	player;
	t_img		img;
}				t_game;

//----------------mlx----------------//

//---mlx_utils.c---//
int				handle_close(void *game_ptr);
void			free_mlx(t_game *game);
int				handle_key(int keycode, void *game_ptr);
void			mlx_inits(t_game *game);


//----------------parsing----------------//

//---parse_elements.c---//
int				parse_texture(char *line, char **texture);
int				parse_color(char *line, t_color *color);

//---parse-file---//
int				is_map_char(char c);
int				is_map_line(char *line);
int				parse_file(char *filename, t_game *game);

//---parse_identifiers.c---//
void			parse_element(char *line, t_game *game);

//---parse_map.c---///
int				read_map(int fd, char *first_line, t_game *game,
					char *filename);

//---parse_utils.c---//
int				is_empty_line(char *line);
char			*skip_identifiers(char *line);

//---validate_file.c---//
int				validate_extension(char *filename);
int				check_all_elements_parsed(t_game *game);

//---validate_map.c---//
int				validate_map(t_game *game);

//---validate_texture---//
int				validate_textures(t_game *game);

//----------------utils----------------//

//---error.c---//
void			print_error(char *msg);
void			exit_error(char *msg, t_game *game);
void			free_game(t_game *game);

#endif
