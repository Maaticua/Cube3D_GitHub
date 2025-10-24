/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:24:08 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 16:24:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	if (size > 0)
	{
		while (src[i] && (dst_len + i) < size - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (src_len + dst_len);
}
/*
#include <stdio.h>

int main(void)
{
	char dest[20] = "Hello";
	const char *src = " World";
	size_t size = 15;
	size_t result;

	result = ft_strlcat(dest, src, size);
	printf("Result: %zu\n", result);
	printf("Destination: %s\n", dest);

	return 0;
}
*/
