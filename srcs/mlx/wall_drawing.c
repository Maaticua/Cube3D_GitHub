/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:52:07 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/09 13:43:17 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall_color(t_game *game, t_rc_ctx *rc_ctx, int wall_color)
{
	if (rc_ctx->side == 0)
		rc_ctx->perp_wall_dist = (rc_ctx->map_x - game->player.pos_x
				+ (1 - rc_ctx->step_x) / 2) / rc_ctx->ray_dir_x;
	else
		rc_ctx->perp_wall_dist = (rc_ctx->map_y - game->player.pos_y
				+ (1 - rc_ctx->step_y) / 2) / rc_ctx->ray_dir_y;
	rc_ctx->line_height = (int)(WINDOW_HEIGHT / rc_ctx->perp_wall_dist);
	rc_ctx->draw_start = -rc_ctx->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rc_ctx->draw_start < 0)
		rc_ctx->draw_start = 0;
	rc_ctx->draw_end = rc_ctx->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rc_ctx->draw_end >= WINDOW_HEIGHT)
		rc_ctx->draw_end = WINDOW_HEIGHT - 1;
	while (rc_ctx->draw_start < rc_ctx->draw_end)
	{
		put_pixel(game->img, rc_ctx->x, rc_ctx->draw_start, wall_color);
		rc_ctx->draw_start++;
	}
}

void	draw_loop(t_game *game, t_rc_ctx *rc_ctx, t_wall_texture *wall_texture)
{
	unsigned int	color;

	while (rc_ctx->draw_start < rc_ctx->draw_end)
	{
		wall_texture->y = (int)wall_texture->position
			% wall_texture->img->height;
		if (wall_texture->y >= wall_texture->img->height)
			wall_texture->y = wall_texture->img->height - 1;
		if (wall_texture->y < 0)
			wall_texture->y = 0;
		wall_texture->offset = wall_texture->y
			* wall_texture->img->line_length
			+ wall_texture->x * (wall_texture->img->bits_per_pixel / 8);
		color = *(unsigned int *)(wall_texture->img->addr
				+ wall_texture->offset);
		put_pixel(game->img, rc_ctx->x, rc_ctx->draw_start, color);
		wall_texture->position += rc_ctx->step_y;
		rc_ctx->draw_start++;
	}
}

void	vertical_wall_math(t_game *game, t_rc_ctx *rc_ctx,
	t_wall_texture *wall_texture)
{
	double	wallx;

	rc_ctx->perp_wall_dist = (rc_ctx->map_x - game->player.pos_x
			+ (1 - rc_ctx->step_x) / 2) / rc_ctx->ray_dir_x;
	wallx = game->player.pos_y + rc_ctx->perp_wall_dist * rc_ctx->ray_dir_y;
	wallx -= floor(wallx);
	if (rc_ctx->ray_dir_x > 0)
	{
		wall_texture->img = game->textures.west_img;
		wall_texture->x = wall_texture->img->width
			- 1 - (int)(wallx * wall_texture->img->width);
	}
	else
	{
		wall_texture->img = game->textures.east_img;
		wall_texture->x = (int)(wallx * wall_texture->img->width);
	}
}

void	horizontal_wall_math(t_game *game, t_rc_ctx *rc_ctx,
	t_wall_texture *wall_texture)
{
	double	wallx;

	rc_ctx->perp_wall_dist = (rc_ctx->map_y - game->player.pos_y
			+ (1 - rc_ctx->step_y) / 2) / rc_ctx->ray_dir_y;
	wallx = game->player.pos_x + rc_ctx->perp_wall_dist * rc_ctx->ray_dir_x;
	wallx -= floor(wallx);
	if (rc_ctx->ray_dir_y < 0)
	{
		wall_texture->img = game->textures.south_img;
		wall_texture->x = wall_texture->img->width
			- 1 - (int)(wallx * wall_texture->img->width);
	}
	else
	{
		wall_texture->img = game->textures.north_img;
		wall_texture->x = (int)(wallx * wall_texture->img->width);
	}
}

void	draw_wall_texture(t_game *game, t_rc_ctx *rc_ctx)
{
	t_wall_texture	wall_texture;

	if (rc_ctx->side == 0)
		vertical_wall_math(game, rc_ctx, &wall_texture);
	else
		horizontal_wall_math(game, rc_ctx, &wall_texture);
	rc_ctx->line_height = (int)(WINDOW_HEIGHT / rc_ctx->perp_wall_dist);
	rc_ctx->step_y = (double)wall_texture.img->height
		/ (double)rc_ctx->line_height;
	rc_ctx->draw_start = -rc_ctx->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rc_ctx->draw_start < 0)
		rc_ctx->draw_start = 0;
	rc_ctx->draw_end = rc_ctx->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rc_ctx->draw_end >= WINDOW_HEIGHT)
		rc_ctx->draw_end = WINDOW_HEIGHT - 1;
	wall_texture.position = (rc_ctx->draw_start
			- WINDOW_HEIGHT / 2 + rc_ctx->line_height / 2) * rc_ctx->step_y;
	draw_loop(game, rc_ctx, &wall_texture);
}
