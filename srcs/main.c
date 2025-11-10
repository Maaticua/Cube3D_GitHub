/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:07:25 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/10 14:57:37 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->floor.r = -1;
	game->floor.g = -1;
	game->floor.b = -1;
	game->ceilling.r = -1;
	game->ceilling.g = -1;
	game->ceilling.b = -1;
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
	mlx_hook(game.win, 2, KeyPressMask, handle_key, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
