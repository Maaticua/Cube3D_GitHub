/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:07:25 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/05 16:17:40 by awaegaer         ###   ########.fr       */
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

void	free_mlx(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_game(&game);
}

int	handle_key(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	if
}

int	handle_close(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	free_mlx(game);
	exit (EXIT_SUCCESS);
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
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		free_game(&game);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, 800, 600, "Larry's Labyrinth");
	if (!game.win)
	{
		free(game.mlx);
		free_game(&game);
		return (1);
	}
	mlx_hook(game.win, 2, 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);

	printf("✅ Parsing successful!\n");
	printf("NO: %s\n", game.textures.north);
	printf("SO: %s\n", game.textures.south);
	printf("WE: %s\n", game.textures.west);
	printf("EA: %s\n", game.textures.east);
	printf("Floor: RGB(%d,%d,%d)\n", game.floor.r, game.floor.g, game.floor.b);
	printf("Ceiling: RGB(%d,%d,%d)\n", game.ceilling.r, game.ceilling.g,
		game.ceilling.b);

	return (0);
}
