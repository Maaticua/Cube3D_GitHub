/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:54:09 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/12 14:19:22 by macaruan         ###   ########.fr       */
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
		return (rc_ctx->step_y = -1, rc_ctx->side_dist_y = (player->pos_y
				- rc_ctx->map_y) * rc_ctx->delta_dist_y, 42);
	else
		return (rc_ctx->step_y = 1, rc_ctx->side_dist_y = (rc_ctx->map_y + 1.0
				- player->pos_y) * rc_ctx->delta_dist_y, 42);
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

// void	project_ray_until_wall(t_game *game, t_rc_ctx *rc_ctx)
// {
// 	digital_differential_analysis_ops(&game->player, rc_ctx);
// 	while (1)
// 	{
// 		if (rc_ctx->map_y < 0 || rc_ctx->map_y >= game->map.height
// 			|| rc_ctx->map_x < 0 || rc_ctx->map_x >= game->map.width)
// 			break ;
// 		if (game->map.grid[rc_ctx->map_y][rc_ctx->map_x] == '1')
// 			break ;
// 		if (rc_ctx->side_dist_x < rc_ctx->side_dist_y)
// 		{
// 			rc_ctx->map_x += rc_ctx->step_x;
// 			rc_ctx->side_dist_x += rc_ctx->delta_dist_x;
// 			rc_ctx->side = 0;
// 		}
// 		else
// 		{
// 			rc_ctx->map_y += rc_ctx->step_y;
// 			rc_ctx->side_dist_y += rc_ctx->delta_dist_y;
// 			rc_ctx->side = 1;
// 		}
// 		//digital_differential_analysis_ops(&game->player, rc_ctx);
// 	}
// }

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
		rc_ctx.ray_dir_x = game->player.dir_x + game->player.cam_x
			* rc_ctx.camera_x;
		rc_ctx.ray_dir_y = game->player.dir_y + game->player.cam_y
			* rc_ctx.camera_x;
		rc_ctx.map_x = (int)game->player.pos_x;
		rc_ctx.map_y = (int)game->player.pos_y;
		project_ray_until_wall(game, &rc_ctx);
		draw_wall_texture(game, &rc_ctx);
		rc_ctx.x++;
	}
}
