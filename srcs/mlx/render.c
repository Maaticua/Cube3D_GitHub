/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:54:48 by awaegaer          #+#    #+#             */
/*   Updated: 2025/12/15 16:40:32 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8)); // saute y lignes, avance de x pixels, coverti bits en byte
	*(unsigned int *)(img->addr + offset) = color; // ecrit couleur a pose memoir
}

int	create_color(int r, int g, int b)
{
	return ((int)((r << 16) | (g << 8) | b)); // 0xRRGGBB
}

void	render_floor_n_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	x = 0;
	y = 0;
	floor_color = create_color(game->floor.r, game->floor.g, game->floor.b);
	ceiling_color = create_color(game->ceiling.r, game->ceiling.g,
			game->ceiling.b);
	while (y < WINDOW_HEIGHT)
	{
		while (x < WINDOW_WIDTH)
		{
			if (y < (WINDOW_HEIGHT / 2))
				put_pixel(game->img, x, y, ceiling_color);
			else if(y >= (WINDOW_HEIGHT / 2))
				put_pixel(game->img, x, y, floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	rotate_left_or_right(t_game *game, double angle)
{
	double	temp_dir_x;
	double	temp_cam_x;

	temp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = temp_dir_x * sin(angle) + game->player.dir_y * cos(angle);
	temp_cam_x = game->player.cam_x;
	game->player.cam_x = game->player.cam_x * cos(angle) - game->player.cam_y * sin(angle);
	game->player.cam_y = temp_cam_x * sin(angle) + game->player.cam_y * cos(angle);
}

void	moove_forward_backward_left_or_right(t_game * game, double ms)
{
	double	temp_pos_x;
	double	temp_pos_y;

	temp_pos_x = 0;
	temp_pos_y = 0;
	if (game->moove_forward)
		temp_pos_x = game->player.pos_x + game->player.dir_x * ms;
	else if (game->moove_backward)
		temp_pos_x = game->player.pos_x - game->player.dir_x * ms;
	else if (game->moove_right)
		temp_pos_x = game->player.pos_x - game->player.dir_y * ms;
	else if (game->moove_left)
		temp_pos_x = game->player.pos_x + game->player.dir_y * ms;
	if (game->moove_forward)
		temp_pos_y = game->player.pos_y + game->player.dir_y * ms;
	else if (game->moove_backward)
		temp_pos_y = game->player.pos_y - game->player.dir_y * ms;
	else if (game->moove_right)
		temp_pos_y = game->player.pos_y + game->player.dir_x * ms;
	else if (game->moove_left)
		temp_pos_y = game->player.pos_y - game->player.dir_x * ms;
	if (game->map.grid[(int)temp_pos_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = temp_pos_y;
	if (game->map.grid[(int)game->player.pos_y][(int)temp_pos_x] != '1')
		game->player.pos_x = temp_pos_x;
}

void	update_pos_n_dir(t_game *game)
{
	if (game->moove_backward || game->moove_forward || game->moove_left || game->moove_right)
		moove_forward_backward_left_or_right(game, 0.01);
	if (game->rotate_right)
		rotate_left_or_right(game, 0.01);
	else if (game->rotate_left)
		rotate_left_or_right(game, -0.01);
}

int	render_frame(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	update_pos_n_dir(game);
	render_floor_n_ceiling(game);
	ray_casting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_ptr, 0, 0);
	return (0);
}

