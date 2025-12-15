/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:54:09 by awaegaer          #+#    #+#             */
/*   Updated: 2025/12/15 14:15:55 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	digital_differential_analysis_ops(t_player *player, t_rc_ctx *rc_ctx)
{
	rc_ctx->delta_dist_x = fabs(1 / rc_ctx->ray_dir_x);
	rc_ctx->delta_dist_y = fabs(1 / rc_ctx->ray_dir_y);
	if (rc_ctx->ray_dir_x < 0)
	{
		rc_ctx->step_x = -1;
		rc_ctx->side_dist_x = (player->pos_x - rc_ctx->map_x)
			* rc_ctx->delta_dist_x;
	}
	else
	{
		rc_ctx->step_x = 1;
		rc_ctx->side_dist_x = (rc_ctx->map_x + 1.0 - player->pos_x)
			* rc_ctx->delta_dist_x;
	}
	if (rc_ctx->ray_dir_y < 0)
		return (rc_ctx->step_y = -1, rc_ctx->side_dist_y
			= (player->pos_y - rc_ctx->map_y) * rc_ctx->delta_dist_y, 42);
	else
		return (rc_ctx->step_y = 1, rc_ctx->side_dist_y
			= (rc_ctx->map_y + 1.0 - player->pos_y) * rc_ctx->delta_dist_y, 42);
}

void	project_ray_until_wall(t_game *game, t_rc_ctx *rc_ctx)
{
	digital_differential_analysis_ops(&game->player, rc_ctx);
	while (game->map.grid[rc_ctx->map_y][rc_ctx->map_x] != '1')
	{
		if (rc_ctx->side_dist_x < rc_ctx->side_dist_y)
		{
			rc_ctx->map_x += rc_ctx->step_x;
			rc_ctx->side_dist_x += rc_ctx->delta_dist_x;
			rc_ctx->side = 0;
		}
		else
		{
			rc_ctx->map_y += rc_ctx->step_y;
			rc_ctx->side_dist_y += rc_ctx->delta_dist_y;
			rc_ctx->side = 1;
		}
		digital_differential_analysis_ops(&game->player, rc_ctx);
	}
}

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

void	draw_wall_texture(t_game *game, t_rc_ctx *rc_ctx)
{
	double			wallX; // coord de contact avec mur
	int				texture_X; // colone de la text
	int				texture_Y;
	double			texture_position;
	int				texture_offset;
	t_img			*texture_img;
	unsigned int	color;

	if (rc_ctx->side == 0) // mur vertical
	{
		rc_ctx->perp_wall_dist = (rc_ctx->map_x - game->player.pos_x
				+ (1 - rc_ctx->step_x) / 2) / rc_ctx->ray_dir_x;
		wallX = game->player.pos_y + rc_ctx->perp_wall_dist * rc_ctx->ray_dir_y;
		wallX -= floor(wallX);
		// texture_X = (int)(wallX * game->textures.east_img->width);
		if (rc_ctx->ray_dir_x > 0) // texture ouest
		{
			texture_img = game->textures.west_img;
			texture_X = texture_img->width - 1 - (int)(wallX * texture_img->width);
		}
		else // texture est
		{
			texture_img = game->textures.east_img;
			texture_X = (int)(wallX * texture_img->width);
		}
	}
	else // mur horizontal
	{
		rc_ctx->perp_wall_dist = (rc_ctx->map_y - game->player.pos_y
				+ (1 - rc_ctx->step_y) / 2) / rc_ctx->ray_dir_y;
		wallX = game->player.pos_x + rc_ctx->perp_wall_dist * rc_ctx->ray_dir_x;
		wallX -= floor(wallX);
		if (rc_ctx->ray_dir_y < 0) // texture sud
		{
			texture_img = game->textures.south_img;
			texture_X = texture_img->width - 1 - (int)(wallX * texture_img->width);
		}
		else // texture nord
		{
			texture_img = game->textures.north_img;
			texture_X = (int)(wallX * texture_img->width);
		}
	}
	rc_ctx->line_height = (int)(WINDOW_HEIGHT / rc_ctx->perp_wall_dist);
	rc_ctx->step_y = (double)texture_img->height / (double)rc_ctx->line_height;
	rc_ctx->draw_start = -rc_ctx->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rc_ctx->draw_start < 0)
		rc_ctx->draw_start = 0;
	rc_ctx->draw_end = rc_ctx->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rc_ctx->draw_end >= WINDOW_HEIGHT)
		rc_ctx->draw_end = WINDOW_HEIGHT - 1;
	texture_position = (rc_ctx->draw_start - WINDOW_HEIGHT / 2 + rc_ctx->line_height / 2) * rc_ctx->step_y;
	// rc_ctx->step_y = 1/4;
	while (rc_ctx->draw_start < rc_ctx->draw_end)
	{
		texture_Y = (int)texture_position % texture_img->height;
		if (texture_Y >= texture_img->height)
			texture_Y = texture_img->height - 1;
		if (texture_Y < 0)
			texture_Y = 0;
		texture_offset = texture_Y * texture_img->line_length + texture_X * (texture_img->bits_per_pixel / 8);
		color = *(unsigned int *)(texture_img->addr + texture_offset);
		put_pixel(game->img, rc_ctx->x, rc_ctx->draw_start, color);
		texture_position += rc_ctx->step_y;
		rc_ctx->draw_start++;
	}
}

void	ray_casting(t_game *game)
{
	t_rc_ctx	rc_ctx;
	int			wall_color;

	wall_color = create_color(127, 0, 255);
	ft_memset(&rc_ctx, 0, sizeof(t_rc_ctx));
	rc_ctx.x = 0;
	while (rc_ctx.x < WINDOW_WIDTH)
	{
		rc_ctx.camera_x = 2 * ((double)rc_ctx.x / (double)WINDOW_WIDTH) - 1;
		rc_ctx.ray_dir_x = game->player.dir_x
			+ game->player.cam_x * rc_ctx.camera_x;
		rc_ctx.ray_dir_y = game->player.dir_y
			+ game->player.cam_y * rc_ctx.camera_x;
		rc_ctx.map_x = (int)game->player.pos_x;
		rc_ctx.map_y = (int)game->player.pos_y;
		project_ray_until_wall(game, &rc_ctx);
		draw_wall_texture(game, &rc_ctx);
		rc_ctx.x++;
	}
}
