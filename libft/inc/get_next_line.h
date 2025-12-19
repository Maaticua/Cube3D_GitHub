/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:45:50 by awaegaer          #+#    #+#             */
/*   Updated: 2025/12/17 15:21:14 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include "libft.h"

char	*get_next_line(int fd);
// char	*ft_strchr(const char *s, int c);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
