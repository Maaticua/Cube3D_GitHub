/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:07:56 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:53:28 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*cpy;

	i = 0;
	while (ft_strrchr(set, s1[i]) != 0 && s1[i] != '\0')
		i++;
	start = i;
	if (ft_strlen(s1) > 0)
		i = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[i]) != 0 && i > 0 && start < i)
		i--;
	if (ft_strlen(s1) > 0)
		i++;
	end = i;
	cpy = (char *) malloc(end - start + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1 + start, end - start + 1);
	return (cpy);
}
/*
#include <stdio.h>

int main(void)
{
	char *s1 = "   Hello, World!   ";
	char *set = " ";
	char *trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	if (trimmed_str)
	{
		printf("Original: '%s'\n", s1);
		printf("Trimmed: '%s'\n", trimmed_str);
		free(trimmed_str);
	}
	else
	{
		printf("Memory allocation failed\n");
	}

	return 0;
}
*/
