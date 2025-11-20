/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:45:29 by awaegaer          #+#    #+#             */
/*   Updated: 2025/11/20 18:21:33 by awaegaer         ###   ########.fr       */
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

void	free_textures_imgs(t_game *game)
{
	if (game->textures.east_img->img_ptr)
		mlx_destroy_image(game->mlx, game->textures.east_img->img_ptr);
	if (game->textures.west_img->img_ptr)
		mlx_destroy_image(game->mlx, game->textures.west_img->img_ptr);
	if (game->textures.north_img->img_ptr)
		mlx_destroy_image(game->mlx, game->textures.north_img->img_ptr);
	if (game->textures.south_img->img_ptr)
		mlx_destroy_image(game->mlx, game->textures.south_img->img_ptr);
	if (game->textures.east_img)
		free(game->textures.east_img);
	game->textures.east_img = NULL;
	if (game->textures.west_img)
		free(game->textures.west_img);
	game->textures.west_img = NULL;
	if (game->textures.north_img)
		free(game->textures.north_img);
	game->textures.north_img = NULL;
	if (game->textures.south_img)
		free(game->textures.south_img);
	game->textures.south_img = NULL;
}

void	init_textures_imgs(t_game *game)
{
	game->textures.east_img = malloc(sizeof(t_img));
	game->textures.west_img = malloc(sizeof(t_img));
	game->textures.south_img = malloc(sizeof(t_img));
	game->textures.north_img = malloc(sizeof(t_img));
	if (!game->textures.east_img || !game->textures.west_img || !game->textures.north_img || !game->textures.south_img)
		free_mlx(game);
	img_init(game->textures.east_img, game, game->textures.east);
	img_init(game->textures.west_img, game, game->textures.west);
	img_init(game->textures.north_img, game, game->textures.north);
	img_init(game->textures.south_img, game, game->textures.south);
}
