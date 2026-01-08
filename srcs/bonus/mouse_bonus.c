/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:07:25 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/08 15:44:48 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define MOUSE_SENSITIVITY 0.002

int	handle_mouse_move(int x, int y, void *game_ptr)
{
	t_game	*game;
	int		delta_x;
	double	angle;

	game = (t_game *)game_ptr;
	(void)y;
	if (!game->mouse_enabled)
	{
		game->mouse_last_x = x;
		game->mouse_enabled = 1;
		return (0);
	}
	delta_x = x - game->mouse_last_x;
	game->mouse_last_x = x;
	if (delta_x != 0)
	{
		angle = delta_x * MOUSE_SENSITIVITY;
		rotate_left_or_right(game, angle);
	}
	return (0);
}
