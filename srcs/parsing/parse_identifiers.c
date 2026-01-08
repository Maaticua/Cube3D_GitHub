/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:40:43 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/22 16:18:25 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_north_south(char *line, t_game *game, int fd)
{
	char	*path;

	if (ft_strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.north)
			exit_error("Error\nDuplicate NO texture", game, line, fd);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.north))
			exit_error("Error\nInvalid NO texture", game, line, fd);
		return (1);
	}
	if (ft_strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.south)
			exit_error("Error\nDuplicate SO texture", game, line, fd);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.south))
			exit_error("Error\nInvalid SO texture", game, line, fd);
		return (1);
	}
	return (0);
}

static int	parse_west_east(char *line, t_game *game, int fd)
{
	char	*path;
	if (ft_strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.west)
			exit_error("Error\nDuplicate WE texture", game, line, fd);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.west))
			exit_error("Error\nInvalid WE texture", game, line, fd);
		return (1);
	}
	if (ft_strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
	{
		if (game->textures.east)
			exit_error("Error\nDuplicate EA texture", game, line, fd);
		path = skip_identifiers(line);
		if (!parse_texture(path, &game->textures.east))
			exit_error("Error\nInvalid EA texture", game, line, fd);
		return (1);
	}
	return (0);
}

static int	parse_floor_ceiling(char *line, t_game *game, int fd)
{
	char	*colors;

	if (ft_strncmp(line, "F", 1) == 0 && (line[1] == ' ' || line[1] == '\t'))
	{
		if (game->floor.r != -1)
			exit_error("Error\nDuplicate floor color", game, line, fd);
		colors = skip_identifiers(line);
		if (!parse_color(colors, &game->floor))
			exit_error("Error\nInvalid floor color", game, line, fd);
		return (1);
	}
	if (ft_strncmp(line, "C", 1) == 0 && (line[1] == ' ' || line[1] == '\t'))
	{
		if (game->ceiling.r != -1)
			exit_error("Error\nDuplicate ceiling color", game, line, fd);
		colors = skip_identifiers(line);
		if (!parse_color(colors, &game->ceiling))
			exit_error("Error\nInvalid ceiling color", game, line, fd);
		return (1);
	}
	return (0);
}

void	parse_element(char *line, t_game *game, int fd)
{
	int	count;

	count = 0;
	count += parse_north_south(line, game, fd);
	count += parse_west_east(line, game, fd);
	count += parse_floor_ceiling(line, game, fd);
	if (count == 0)
		exit_error ("Error\nInvalid config line", game, line, fd);
}
