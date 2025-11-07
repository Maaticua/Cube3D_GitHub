/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:57:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 14:57:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
#include <stdio.h>

int main(void)
{
	char src[] = "Hello, World!";
	char dst[20];
	size_t copied;

	copied = ft_strlcpy(dst, src, sizeof(dst));
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dst);
	printf("Length of source: %zu\n", copied);

	return 0;
}
*/
