/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:43:55 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/13 16:45:37 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_sprite_transform(t_game *game, int i, double *transform)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = game->sprite_data.sprites[i].x - game->player.pos_x;
	sprite_y = game->sprite_data.sprites[i].y - game->player.pos_y;
	inv_det = 1.0 / (game->player.cam_x * game->player.dir_y
			- game->player.dir_x * game->player.cam_y);
	transform[0] = inv_det * (game->player.dir_y * sprite_x - game->player.dir_x
			* sprite_y);
	transform[1] = inv_det * (-game->player.cam_y * sprite_x
			+ game->player.cam_x * sprite_y);
}

static void	calculate_sprite_screen(double *transform, int *screen_data)
{
	int	sprite_screen_x;
	int	sprite_height;

	sprite_screen_x = (int)(WINDOW_WIDTH / 2)*(1 + transform[0]
			/ transform[1]);
	sprite_height = ft_abs((int)(WINDOW_HEIGHT / transform[1]));
	screen_data[0] = sprite_screen_x;
	screen_data[1] = sprite_height;
	screen_data[2] = -sprite_height / 2 + WINDOW_HEIGHT / 2;
	if (screen_data[2] < 0)
		screen_data[2] = 0;
	screen_data[3] = sprite_height / 2 + WINDOW_HEIGHT / 2;
	if (screen_data[3] == WINDOW_HEIGHT)
		screen_data[3] = WINDOW_HEIGHT - 1;
	screen_data[4] = -sprite_height / 2 + sprite_screen_x;
	if (screen_data[4] < 0)
		screen_data[4] = 0;
	screen_data[5] = sprite_height / 2 + sprite_screen_x;
	if (screen_data[5] >= WINDOW_WIDTH)
		screen_data[5] = WINDOW_WIDTH - 1;
}

static void	draw_sprite_pixel(t_game *game, t_img *frame, int *coords)
{
	int	tex_x;
	int	tex_y;
	int	color;
	int	offset;

	tex_x = (coords[0] - coords[4]) * frame->width / coords[1];
	tex_y = (coords[2] - coords[5]) * frame->height / coords[1];
	offset = (tex_y * frame->line_length) + (tex_x * (frame->bits_per_pixel
				/ 8));
	color = *(unsigned int *)(frame->addr + offset);
	if ((color & 0x00FFFFFF) != 0)
		put_pixel(game->img, coords[0], coords[2], color);
}

static void	draw_sprite_column(t_game *game, t_img *frame, int *data)
{
	int		coords[6];
	double	sprite_dist;

	if (data[0] < 0 || data[0] >= WINDOW_WIDTH)
		return ;
	sprite_dist = *((double *)&data[6]);
	coords[0] = data[0];
	coords[1] = data[1];
	coords[2] = data[2];
	coords[4] = data[4];
	coords[5] = data[2];
	while (coords[2] < data[3])
	{
		if (sprite_dist < game->zbuffer[coords[0]])
			draw_sprite_pixel(game, frame, coords);
		coords[2]++;
	}
}

void	draw_sprite(t_game *game, int i)
{
	double	transform[2];
	int		screen_data[8];
	t_img	*fram;
	int		x;

	calculate_sprite_transform(game, i, transform);
	if (transform[1] <= 0)
		return ;
	calculate_sprite_screen(transform, screen_data);
	*((double *)&screen_data[6]) = transform[1];
	fram = game->sprite_data.frames[game->sprite_data.sprites[i].current_frame];
	x = screen_data[4];
	while (x < screen_data[5])
	{
		screen_data[0] = x;
		draw_sprite_column(game, fram, screen_data);
		x++;
	}
}
