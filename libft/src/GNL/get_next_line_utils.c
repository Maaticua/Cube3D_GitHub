/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:58:19 by awaegaer          #+#    #+#             */
/*   Updated: 2025/09/26 18:20:27 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = -1;
// 	while (s[++i])
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)(s + i));
// 	if (s[i] == (unsigned char)c)
// 		return ((char *)(s + i));
// 	return (NULL);
// }

char	*gnl_strdup(const char *s)
{
	char	*sdup;

	sdup = malloc(gnl_strlen(s) + 1);
	if (!sdup)
		return (NULL);
	ft_strlcpy(sdup, s, gnl_strlen(s) + 1);
	return (sdup);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (i - 1);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*sub;

// 	if (!s)
// 		return (NULL);
// 	if (start >= gnl_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > gnl_strlen(s) - start)
// 		len = gnl_strlen(s) - start;
// 	sub = (char *)malloc(len + 1);
// 	if (!sub)
// 		return (NULL);
// 	ft_strlcpy(sub, s + start, len + 1);
// 	return (sub);
// }

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (NULL);
	len_s1 = gnl_strlen(s1);
	if (s2)
		len_s2 = gnl_strlen(s2);
	else
		len_s2 = 0;
	s3 = (char *) malloc(len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	if (s2)
		ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	return (s3);
}
