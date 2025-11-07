/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:51:48 by macaruan          #+#    #+#             */
/*   Updated: 2025/10/28 15:05:17 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	validate_texture_file(char *path)
{
	int		fd;
	char	buffer[1];

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error("Error\nCannot open texture file"), 0);
	if (read(fd, buffer, 1) < 0)
	{
		close(fd);
		return (print_error("Error\nCannot read texture file"), 0);
	}
	close(fd);
	return (1);
}

static int	validate_xpm_extension(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5)
		return (print_error("Error\nInvalid texture filename"), 0);
	if (ft_strcmp(path + len - 4, ".xpm") != 0)
		return (print_error("Error\nTexture must be .xpm file"), 0);
	return (1);
}

int	validate_textures(t_game *game)
{
	if (!validate_xpm_extension(game->textures.north))
		return (0);
	if (!validate_texture_file(game->textures.north))
		return (0);
	if (!validate_xpm_extension(game->textures.south))
		return (0);
	if (!validate_texture_file(game->textures.south))
		return (0);
	if (!validate_xpm_extension(game->textures.west))
		return (0);
	if (!validate_texture_file(game->textures.west))
		return (0);
	if (!validate_xpm_extension(game->textures.east))
		return (0);
	if (!validate_texture_file(game->textures.east))
		return (0);
	return (1);
}
