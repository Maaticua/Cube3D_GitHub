/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:18:34 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/13 12:24:56 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// int	moovement_keys(int keycode, t_game *game)
// {
// 	if (keycode == XK_w || keycode == XK_W)
// 		return (game->moove_backward = 0, game->moove_left = 0,
// 			game->moove_right = 0, game->moove_forward = 1, 0);
// 	else if (keycode == XK_s || keycode == XK_S)
// 		return (game->moove_backward = 1, game->moove_left = 0,
// 			game->moove_right = 0, game->moove_forward = 0, 0);
// 	else if (keycode == XK_a || keycode == XK_A)
// 		return (game->moove_backward = 0, game->moove_left = 1,
// 			game->moove_right = 0, game->moove_forward = 0, 0);
// 	else if (keycode == XK_d || keycode == XK_D)
// 		return (game->moove_backward = 0, game->moove_left = 0,
// 			game->moove_right = 1, game->moove_forward = 0, 0);
// 	return (0);
// }

int	moovement_keys(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->moove_forward = 1;
	else if (keycode == XK_s || keycode == XK_S)
		game->moove_backward = 1;
	else if (keycode == XK_a || keycode == XK_A)
		game->moove_left = 1;
	else if (keycode == XK_d || keycode == XK_D)
		game->moove_right = 1;
	return (0);
}

int	handle_key(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *)game_ptr;
	if (keycode == XK_Left || keycode == XK_KP_Left)
	{
		game->rotate_right = 0;
		game->rotate_left = 1;
	}
	else if (keycode == XK_Right || keycode == XK_KP_Right)
	{
		game->rotate_left = 0;
		game->rotate_right = 1;
	}
	moovement_keys(keycode, game);
	if (keycode == XK_Escape)
		handle_close(game_ptr);
	return (0);
}

int	handle_key_release(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *)game_ptr;
	if (keycode == XK_Left || keycode == XK_KP_Left)
		game->rotate_left = 0;
	else if (keycode == XK_Right || keycode == XK_KP_Right)
		game->rotate_right = 0;
	if (keycode == XK_w || keycode == XK_W)
		game->moove_forward = 0;
	else if (keycode == XK_s || keycode == XK_S)
		game->moove_backward = 0;
	else if (keycode == XK_a || keycode == XK_A)
		game->moove_left = 0;
	else if (keycode == XK_d || keycode == XK_D)
		game->moove_right = 0;
	return (0);
}
