/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:40:43 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/10 17:18:03 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	parse_north_south(char *line, t_game *game)
{
	char	*path;

	if (ft_strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.north)
			exit_error("Error\nDuplicate NO texture", game);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.north))
			exit_error("Error\nInvalid NO texture", game);
	}
	if (ft_strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.south)
			exit_error("Error\nDuplicate SO texture", game);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.south))
			exit_error("Error\nInvalid SO texture", game);
	}
}

static void	parse_west_east(char *line, t_game *game)
{
	char	*path;

	if (ft_strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.west)
			exit_error("Error\nDuplicate WE texture", game);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.west))
			exit_error("Error\nInvalid WE texture", game);
	}
	if (ft_strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.east)
			exit_error("Error\nDuplicate EA texture", game);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.east))
			exit_error("Error\nInvalid EA texture", game);
	}
}

static void	parse_floor_ceiling(char *line, t_game *game)
{
	char	*colors;

	if (ft_strncmp(line, "F", 1) == 0 && (line[1] == ' ' || line[1] == '\t'))
	{
		if (game->floor.r != -1)
			exit_error("Error\nDuplicate floor color", game);
		colors = skip_identifiers(line);
		if (!parse_color(colors, &game->floor))
			exit_error("Error\nInvalid floor color", game);
	}
	if (ft_strncmp(line, "C", 1) == 0 && (line[1] == ' ' || line[1] == '\t'))
	{
		if (game->ceiling.r != -1)
			exit_error("Error\nDuplicate ceiling color", game);
		colors = skip_identifiers(line);
		if (!parse_color(colors, &game->ceiling))
			exit_error("Error\nInvalid ceiling color", game);
	}
}

void	parse_element(char *line, t_game *game)
{
	parse_north_south(line, game);
	parse_west_east(line, game);
	parse_floor_ceiling(line, game);
}
