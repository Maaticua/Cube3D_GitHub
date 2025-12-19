/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:45:55 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/17 15:21:43 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
}

void	exit_error(char *msg, t_game *game)
{
	print_error(msg);
	free_game(game);
	exit(1);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->textures.north)
		free(game->textures.north);
	if (game->textures.south)
		free(game->textures.south);
	if (game->textures.west)
		free(game->textures.west);
	if (game->textures.east)
		free(game->textures.east);
	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height && game->map.grid[i])
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	if (game->img)
		free(game->img);
}
