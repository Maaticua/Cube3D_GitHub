/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:59:35 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 20:59:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*src;

	i = 0;
	src = (unsigned char *) s;
	while (i < n)
	{
		if (src[i] == (unsigned char) c)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
/*

int main()
{
	char str[] = "Hello, world!";
	char *result;

	result = ft_memchr(str, 'w', sizeof(str));
	if (result != NULL)
		printf("Character found: %c\n", *result);
	else
		printf("Character not found\n");

	result = ft_memchr(str, 'z', sizeof(str));
	if (result != NULL)
		printf("Character found: %c\n", *result);
	else
		printf("Character not found\n");

	return 0;
}
*/
