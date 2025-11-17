/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:45:29 by awaegaer          #+#    #+#             */
/*   Updated: 2025/11/17 15:35:13 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_player_vectors(t_game *game)
{
	if (game->player.orientation == 'N')
		return (game->player.dir_x = 0, game->player.dir_y = -1,
			game->player.cam_x = 0.66, game->player.cam_y = 0, 42);
	else if (game->player.orientation == 'S')
		return (game->player.dir_x = 0, game->player.dir_y = 1,
			game->player.cam_x = -0.66, game->player.cam_y = 0, 42);
	else if (game->player.orientation == 'E')
		return (game->player.dir_x = 1, game->player.dir_y = 0,
			game->player.cam_x = 0, game->player.cam_y = 0.66, 42);
	if (game->player.orientation == 'W')
		return (game->player.dir_x = -1, game->player.dir_y = 0,
			game->player.cam_x = 0, game->player.cam_y = -0.66, 42);
	return (42);
}
