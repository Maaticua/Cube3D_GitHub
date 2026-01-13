/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:24:29 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/13 14:23:38 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_sprite_distance(t_game *game)
{
	int		i;
	double	dx;
	double	dy;

	i = 0;
	while (i < game->sprite_data.count)
	{
		dx = game->sprite_data.sprites[i].x - game->player.pos_x;
		dy = game->sprite_data.sprites[i].y - game->player.pos_y;
		game->sprite_data.sprites[i].distance = dx * dx + dy * dy;
		i++;
	}
}

static void	update_sprite_animation(t_game *game)
{
	int	i;

	game->sprite_data.frame_counter++;
	if (game->sprite_data.frame_counter <= 15)
		return ;
	i = 0;
	while (i < game->sprite_data.count)
	{
		game->sprite_data.sprites[i].current_frame++;
		if (game->sprite_data.sprites[i].current_frame >= SPRITE_FRAMES)
			game->sprite_data.sprites[i].current_frame = 0;
		i++;
	}
	game->sprite_data.frame_counter = 0;
}

void	sort_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < game->sprite_data.count - 1)
	{
		j = 0;
		while (j < game->sprite_data.count - i - 1)
		{
			if (game->sprite_data.sprites[j].distance < game->sprite_data.sprites[j
				+ 1].distance)
			{
				tmp = game->sprite_data.sprites[j];
				game->sprite_data.sprites[j] = game->sprite_data.sprites[j + 1];
				game->sprite_data.sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	render_sprites(t_game *game)
{
	int	i;

	if (game->sprite_data.count == 0)
		return ;
	calculate_sprite_distance(game);
	sort_sprites(game);
	update_sprite_animation(game);
	i = 0;
	while (i < game->sprite_data.count)
	{
		draw_sprite(game, i);
		i++;
	}
}
