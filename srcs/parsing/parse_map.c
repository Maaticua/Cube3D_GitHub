/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:12:33 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/19 17:20:49 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	store_map_line(t_game *game, char *line, int i)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	game->map.grid[i] = ft_strdup(line);
	len = ft_strlen(game->map.grid[i]);
	if (len > game->map.width)
		game->map.width = len;
}

void	has_wrong_map_char(char *line, char **temp, int fd, int cpt, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_map_char(line[i]))
		{
			while (j < cpt)
				free(temp[j++]);
			free(temp);
			close(fd);
			free(line);
			exit_error("Error\nInvalid character in or after map", game);
		}
		i++;
	}
}

static int	collect_lines(int fd, char **temp, char *first_line, t_game *game)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	temp[0] = first_line;
	i = 1;
	line = get_next_line(fd);
	while (line && is_map_line(line))
	{
		temp[i++] = line;
		line = get_next_line(fd);
	}
	if (line)
	{
		has_wrong_map_char(line, temp, fd, i, game);
		free(line);
	}
	return (i);
}

static void	fill_map(t_game *game, char **temp, int count)
{
	int	i;

	game->map.width = 0;
	i = 0;
	while (i < count)
	{
		store_map_line(game, temp[i], i);
		free(temp[i]);
		i++;
	}
	game->map.grid[i] = NULL;
}

int	read_map(int fd, char *first_line, t_game *game, char *filename)
{
	char	**temp;
	int		count;

	(void)filename;
	temp = malloc(sizeof(char *) * 1000);
	if (!temp)
		return (free(first_line), 0);
	count = collect_lines(fd, temp, first_line, game);
	game->map.height = count;
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (free(temp), 0);
	fill_map(game, temp, count);
	free(temp);
	close(fd);
	return (1);
}
