/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:44:34 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:51:10 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;

	sdup = malloc(ft_strlen(s) + 1);
	if (!sdup)
		return (NULL);
	ft_strlcpy(sdup, s, ft_strlen(s) + 1);
	return (sdup);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "Hello, World!";
	char *dup;

	dup = ft_strdup(str);
	if (dup)
	{
		printf("Original: %s\n", str);
		printf("Duplicate: %s\n", dup);
		free(dup);
	}
	else
	{
		printf("Memory allocation failed\n");
	}
	return (0);
}
*/
