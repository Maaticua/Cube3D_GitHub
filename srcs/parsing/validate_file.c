/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:22:54 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/12 15:14:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	validate_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

int	check_all_elements_parsed(t_game *game)
{
	if (!game->textures.north)
		return (print_error("Error\nMissing NO texture"), 0);
	if (!game->textures.south)
		return (print_error("Error\nMissing SO texture"), 0);
	if (!game->textures.east)
		return (print_error("Error\nMissing EA texture"), 0);
	if (!game->textures.west)
		return (print_error("Error\nMissing WE texture"), 0);
	if (game->floor.r == -1)
		return (print_error("Error\nMissing F color"), 0);
	if (game->ceiling.r == -1)
		return (print_error("Error\nMissing C color"), 0);
	return (1);
}
