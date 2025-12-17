/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:49:02 by awaegaer          #+#    #+#             */
/*   Updated: 2025/12/15 16:18:54 by awaegaer         ###   ########.fr       */
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

int	moovement_keys(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		return (game->moove_backward = 0, game->moove_left = 0, game->moove_right = 0,
				game->moove_forward = 1, 0);
	else if (keycode == XK_s || keycode == XK_S)
		return (game->moove_backward = 1, game->moove_left = 0, game->moove_right = 0,
				game->moove_forward = 0, 0);
	else if (keycode == XK_a || keycode == XK_A)
		return (game->moove_backward = 0, game->moove_left = 1, game->moove_right = 0,
				game->moove_forward = 0, 0);
	else if (keycode == XK_d || keycode == XK_D)
		return (game->moove_backward = 0, game->moove_left = 0, game->moove_right = 1,
				game->moove_forward = 0, 0);
	return (0);
}

int	handle_key(int keycode, void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
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

	game = (t_game *) game_ptr;
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
