/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:04:15 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/13 14:22:03 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_sprites(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map.height && count < MAX_SPRITES)
	{
		x = 0;
		while (x < game->map.width && count < MAX_SPRITES)
		{
			if (game->map.grid[y][x] == 'X')
			{
				game->sprite_data.sprites[count].x = x + 0.5;
				game->sprite_data.sprites[count].y = y + 0.5;
				game->sprite_data.sprites[count].current_frame = 0;
				count++;
			}
			x++;
		}
		y++;
	}
	game->sprite_data.count = count;
	game->sprite_data.frame_counter = 0;
}

void	load_sprite_frames(t_game *game)
{
	int		i;
	char	*path[SPRITE_FRAMES];

	path[0] = "./textures/sprite_0.xpm";
	path[1] = "./textures/sprite_1.xpm";
	path[2] = "./textures/sprite_2.xpm";
	path[3] = "./textures/sprite_3.xpm";
	i = 0;
	while (i < SPRITE_FRAMES)
	{
		game->sprite_data.frames[i] = NULL;
		i++;
	}
	i = 0;
	while (i < SPRITE_FRAMES)
	{
		game->sprite_data.frames[i] = malloc(sizeof(t_img));
		if (!game->sprite_data.frames[i])
			return ;
		img_init(game->sprite_data.frames[i], game, path[i]);
		i++;
	}
}

void	free_sprites(t_game *game)
{
	int	i;

	if (!game->mlx)
		return ;
	i = 0;
	while (i < SPRITE_FRAMES)
	{
		if (game->sprite_data.frames[i])
		{
			if (game->sprite_data.frames[i]->img_ptr)
				mlx_destroy_image(game->mlx,
					game->sprite_data.frames[i]->img_ptr);
			free(game->sprite_data.frames[i]);
			game->sprite_data.frames[i] = NULL;
		}
		i++;
	}
}
