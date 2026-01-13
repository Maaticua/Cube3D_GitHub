/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:07:25 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/13 13:55:45 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define MINIMAP_SIZE 20
#define MINIMAP_SCALE 10
#define MINIMAP_MARGIN 20

static void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			screen_x = MINIMAP_MARGIN + x * MINIMAP_SCALE + i;
			screen_y = MINIMAP_MARGIN + y * MINIMAP_SCALE + j;
			if (screen_x >= 0 && screen_x < WINDOW_WIDTH && screen_y >= 0
				&& screen_y < WINDOW_HEIGHT)
				put_pixel(game->img, screen_x, screen_y, color);
			j++;
		}
		i++;
	}
}

static void	draw_player_on_minimap(t_game *game, int center_x, int center_y)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			screen_x = MINIMAP_MARGIN + center_x * MINIMAP_SCALE + i;
			screen_y = MINIMAP_MARGIN + center_y * MINIMAP_SCALE + j;
			if (screen_x >= 0 && screen_x < WINDOW_WIDTH && screen_y >= 0
				&& screen_y < WINDOW_HEIGHT)
				put_pixel(game->img, screen_x, screen_y, 0xFF0000);
			j++;
		}
		i++;
	}
}

static int	get_minimap_color(t_game *game, int map_x, int map_y)
{
	if (map_x >= 0 && map_x < game->map.width && map_y >= 0
		&& map_y < game->map.height)
	{
		if (game->map.grid[map_y][map_x] == '1')
			return (0xFFFFFF);
		else if (game->map.grid[map_y][map_x] == '0')
			return (0x333333);
		else
			return (0x333333);
	}
	return (0x000000);
}

static void	render_minimap_tile(t_game *game, int x, int y)
{
	int	map_x;
	int	map_y;
	int	color;

	map_x = (int)game->player.pos_x - MINIMAP_SIZE / 2 + x;
	map_y = (int)game->player.pos_y - MINIMAP_SIZE / 2 + y;
	color = get_minimap_color(game, map_x, map_y);
	draw_minimap_square(game, x, y, color);
}

void	render_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
		{
			render_minimap_tile(game, x, y);
			x++;
		}
		y++;
	}
	draw_player_on_minimap(game, MINIMAP_SIZE / 2, MINIMAP_SIZE / 2);
}
