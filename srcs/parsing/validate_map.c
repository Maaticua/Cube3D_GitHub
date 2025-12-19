/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:04:08 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/19 15:18:05 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	find_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (game->map.grid[y][++x])
		{
			if (is_player(game->map.grid[y][x]))
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				game->player.orientation = game->map.grid[y][x];
				game->map.grid[y][x] = '0';
				count++;
			}
		}
	}
	if (count != 1)
		return (print_error("Error\nMore or less than 1 Player"), 0);
	return (1);
}

static int	check_borders(t_game *game, int y, int x)
{
	int	len_prev;
	int	len_next;

	if (y == 0 || y == game->map.height - 1)
		return (0);
	if (x == 0 || x == (int)ft_strlen(game->map.grid[y]) - 1)
		return (0);
	len_prev = ft_strlen(game->map.grid[y - 1]);
	len_next = ft_strlen(game->map.grid[y + 1]);
	if (x >= len_prev || game->map.grid[y - 1][x] == ' ')
		return (0);
	if (x >= len_next || game->map.grid[y + 1][x] == ' ')
		return (0);
	if (game->map.grid[y][x - 1] == ' ' || game->map.grid[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (game->map.grid[y][++x])
		{
			if (game->map.grid[y][x] == '0' || is_player(game->map.grid[y][x]))
				if (!check_borders(game, y, x))
					return (print_error("Error\nMap not closed"), 0);
		}
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!find_player(game))
		return (0);
	if (!check_walls(game))
		return (0);
	return (1);
}
