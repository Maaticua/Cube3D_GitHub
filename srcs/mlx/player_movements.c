/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:37:14 by awaegaer          #+#    #+#             */
/*   Updated: 2025/12/19 10:38:15 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left_or_right(t_game *game, double angle)
{
	double	temp_dir_x;
	double	temp_cam_x;

	temp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = temp_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	temp_cam_x = game->player.cam_x;
	game->player.cam_x = game->player.cam_x * cos(angle)
		- game->player.cam_y * sin(angle);
	game->player.cam_y = temp_cam_x * sin(angle)
		+ game->player.cam_y * cos(angle);
}

void	moove_forward_backward_left_or_right(t_game *game, double ms)
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
	if (game->moove_backward || game->moove_forward
		|| game->moove_left || game->moove_right)
		moove_forward_backward_left_or_right(game, 0.01);
	if (game->rotate_right)
		rotate_left_or_right(game, 0.01);
	else if (game->rotate_left)
		rotate_left_or_right(game, -0.01);
}
