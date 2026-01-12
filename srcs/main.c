/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:07:25 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/09 16:36:37 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->floor.r = -1;
	game->floor.g = -1;
	game->floor.b = -1;
	game->ceiling.r = -1;
	game->ceiling.g = -1;
	game->ceiling.b = -1;
	game->img = malloc(sizeof(t_img));
	game->mouse_x = 0;
	game->mouse_last_x = 0;
	game->mouse_enabled = 0;
	if (!game->img)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		print_error("Error\nUsage: ./cub3D <map.cub>");
		return (1);
	}
	init_game(&game);
	if (!parse_file(argv[1], &game))
	{
		free_game(&game);
		return (1);
	}
	mlx_inits(&game);
	init_player_vectors(&game);
	init_textures_imgs(&game);
	load_sprite_frames(&game);
	init_sprites(&game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, KeyPressMask, handle_key, &game);
	mlx_hook(game.win, 3, KeyReleaseMask, handle_key_release, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_hook(game.win, 6, PointerMotionMask, handle_mouse_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
