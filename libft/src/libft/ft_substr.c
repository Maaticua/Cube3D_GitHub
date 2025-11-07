/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:51 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:53:38 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, world!";
	char	*sub;

	sub = ft_substr(str, 7, 5);
	if (sub)
	{
		printf("Substring: %s\n", sub);
		free(sub);
	}
	else
	{
		printf("Failed to allocate memory for substring.\n");
	}
	return (0);
}
*/
