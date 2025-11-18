/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:49:02 by awaegaer          #+#    #+#             */
/*   Updated: 2025/11/18 18:01:13 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_close(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	free_mlx(game);
	exit (EXIT_SUCCESS);
	return (0);
}

void	free_mlx(t_game *game)
{
	free_textures_imgs(game);
	if (game->img->img_ptr)
	{
		mlx_destroy_image(game->mlx, game->img->img_ptr);
		game->img->img_ptr = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		// mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_game(game);
}

int	handle_key(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	if (keycode == XK_Escape)
		handle_close(game_ptr);
	return (0);
}

void	img_init(t_img *img, t_game *game, char *filename)
{
	int	width;
	int	height;

	img->img_ptr = mlx_xpm_file_to_image(game->mlx, filename, &width, &height);
	if (!img->img_ptr)
	{
		free_mlx(game);
		exit (EXIT_FAILURE);
	}
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	mlx_inits(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_game(game);
		exit (EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, 800, 600, "Larry's Labyrinth");
	if (!game->win)
	{
		free_mlx(game);
		exit (EXIT_FAILURE);
	}
	game->img->img_ptr = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img->img_ptr)
	{
		free_mlx(game);
		exit (EXIT_FAILURE);
	}
	game->img->bits_per_pixel = 32;
	game->img->line_length = WINDOW_WIDTH * (game->img->bits_per_pixel / 8);
	game->img->endian = 0;
	game->img->addr = mlx_get_data_addr(game->img->img_ptr,
			&game->img->bits_per_pixel, &game->img->line_length,
			&game->img->endian);
}
