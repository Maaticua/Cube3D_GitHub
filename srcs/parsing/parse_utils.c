/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:58:41 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/23 17:01:28 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*skip_identifiers(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (&line[i]);
}

int	free_temp(char **temp, int i)
{
	int	j;

	j = 0;
	while (*temp && j < i)
		free(temp[j++]);
	free(temp);
	return (1);
}
