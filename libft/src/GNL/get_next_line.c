/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:43:53 by awaegaer          #+#    #+#             */
/*   Updated: 2025/12/19 12:23:04 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *saved)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read > BUFFER_SIZE)
		{
			free(saved);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!saved)
			saved = gnl_strdup("");
		temp = saved;
		saved = gnl_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (saved);
}

static char	*extrat_line(char *saved)
{
	ssize_t	i;
	char	*line;

	i = 0;
	if (!saved)
		return (NULL);
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\n')
		line = ft_substr(saved, 0, i + 1);
	else
		line = ft_substr(saved, 0, i);
	return (line);
}

static char	*update_saved(char *saved)
{
	ssize_t	i;
	char	*new_saved;

	i = 0;
	if (!saved)
		return (NULL);
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\0')
	{
		free(saved);
		return (NULL);
	}
	new_saved = ft_substr(saved, i + 1, gnl_strlen(saved) - i);
	free(saved);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (saved)
		{
			free(saved);
			saved = NULL;
		}
		return (NULL);
	}
	saved = read_buffer(fd, saved);
	if (!saved)
		return (NULL);
	line = extrat_line(saved);
	saved = update_saved(saved);
	return (line);
}
// static char	*read_to_buffer(int fd, char *last_s, char *buffer)
// {
// 	ssize_t	bytesread;
// 	char	*temp;

// 	bytesread = 1;
// 	while (bytesread > 0)
// 	{
// 		bytesread = read(fd, buffer, BUFFER_SIZE);
// 		if (bytesread == -1 || bytesread > BUFFER_SIZE)
// 		{
// 			free (last_s);
// 			return (NULL);
// 		}
// 		else if (bytesread == 0)
// 			break ;
// 		buffer[bytesread] = '\0';
// 		if (!last_s)
// 			last_s = gnl_strdup("");
// 		temp = last_s;
// 		last_s = gnl_strjoin(temp, buffer);
// 		free(temp);
// 		temp = NULL;
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	return (last_s);
// }

// static char	*get_rest_or_end(char *line_buffer)
// {
// 	char	*last_s;
// 	ssize_t	i;

// 	if (!line_buffer)
// 		return (NULL);
// 	i = 0;
// 	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
// 		i++;
// 	if (line_buffer[i] == '\0')
// 		return (NULL);
// 	last_s = ft_substr(line_buffer, i + 1, gnl_strlen(line_buffer) - i);
// 	if (!last_s || *last_s == '\0')
// 	{
// 		free(last_s);
// 		last_s = NULL;
// 	}
// 	line_buffer[i + 1] = '\0';
// 	return (last_s);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*last_s;
// 	char		*buffer;
// 	char		*line_buffer;

// 	if (fd == -1)
// 	{
// 		if (last_s)
// 			free(last_s);
// 		last_s = NULL;
// 		return (NULL);
// 	}
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 	{
// 		if (last_s)
// 			free(last_s);
// 		last_s = NULL;
// 		return (NULL);
// 	}
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	line_buffer = read_to_buffer(fd, last_s, buffer);
// 	free(buffer);
// 	buffer = NULL;
// 	if (!line_buffer)
// 		return (NULL);
// 	if (gnl_strlen(line_buffer) == 1 && line_buffer[0] == '\n')
// 	{
// 		free(last_s);
// 		last_s = NULL;
// 	}
// 	last_s = get_rest_or_end(line_buffer);
// 	return (line_buffer);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	src_len = ft_strlen(src);
// 	if (size > 0)
// 	{
// 		while (src[i] && i < size - 1)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (src_len);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;
// 	size_t	dst_len;

// 	i = 0;
// 	src_len = ft_strlen(src);
// 	dst_len = ft_strlen(dst);
// 	if (size <= dst_len)
// 		return (size + src_len);
// 	if (size > 0)
// 	{
// 		while (src[i] && (dst_len + i) < size - 1)
// 		{
// 			dst[dst_len + i] = src[i];
// 			i++;
// 		}
// 		dst[dst_len + i] = '\0';
// 	}
// 	return (src_len + dst_len);
// }
