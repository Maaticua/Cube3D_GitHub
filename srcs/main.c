/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:07:25 by macaruan          #+#    #+#             */
/*   Updated: 2025/10/30 15:38:06 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../minilibx-linux/mlx.h"

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
	printf("✅ Parsing successful!\n");
	printf("NO: %s\n", game.textures.north);
	printf("SO: %s\n", game.textures.south);
	printf("WE: %s\n", game.textures.west);
	printf("EA: %s\n", game.textures.east);
	printf("Floor: RGB(%d,%d,%d)\n", game.floor.r, game.floor.g, game.floor.b);
	printf("Ceiling: RGB(%d,%d,%d)\n", game.ceilling.r, game.ceilling.g,
		game.ceilling.b);
	free_game(&game);
	return (0);
}
