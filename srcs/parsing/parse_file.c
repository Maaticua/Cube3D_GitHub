/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:23:56 by macaruan          #+#    #+#             */
/*   Updated: 2025/10/28 16:47:03 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	is_map_line(char *line)
{
	int	i;
	int	has_valid_char;

	i = 0;
	has_valid_char = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (!is_map_char(line[i]))
			return (0);
		if (line[i] != ' ' && line[i] != '\t')
			has_valid_char = 1;
		i++;
	}
	return (has_valid_char);
}

static int	read_config_lines(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (is_map_line(line))
			{
				free(line);
				break ;
			}
			parse_element(line, game);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

static int	validate_all(t_game *game)
{
	if (!check_all_elements_parsed(game))
		return (0);
	if (!validate_textures(game))
		return (0);
	return (1);
}

int	parse_file(char *filename, t_game *game)
{
	int	fd;

	if (!validate_extension(filename))
		return (print_error("Error\nInvalid file extension"), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error("Error\nCannot open file"), 0);
	read_config_lines(fd, game);
	if (!validate_all(game))
		return (close(fd), 0);
	close(fd);
	return (1);
}
