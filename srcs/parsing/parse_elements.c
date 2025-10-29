/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:22:47 by macaruan          #+#    #+#             */
/*   Updated: 2025/10/28 15:07:56 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_texture(char *line, char **texture)
{
	char	*path;
	int		i;
	int		start;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	start = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		i++;
	path = ft_substr(line, start, i - start);
	if (!path)
		return (0);
	*texture = path;
	return (1);
}

static int	skip_spaces(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

static int	ft_atoi_rgb(char *str, int *i)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
		count++;
	}
	if (count == 0 || count > 3)
		return (-1);
	return (result);
}

int	parse_color(char *line, t_color *color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = skip_spaces(line, 0);
	r = ft_atoi_rgb(line, &i);
	if (r < 0 || r > 255 || line[i] != ',')
		return (0);
	i++;
	g = ft_atoi_rgb(line, &i);
	if (g < 0 || g > 255 || line[i] != ',')
		return (0);
	i++;
	b = ft_atoi_rgb(line, &i);
	if (b < 0 || b > 255)
		return (0);
	i = skip_spaces(line, i);
	if (line[i] && line[i] != '\n')
		return (0);
	color->r = r;
	color->g = g;
	color->b = b;
	return (1);
}
