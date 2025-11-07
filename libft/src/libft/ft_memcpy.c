/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:01:28 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:49:15 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d == 0 && s == 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *) d);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char src[50] = "This is the source string.";
	char dest[50];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("Destination after memcpy: %s\n", dest);

	return 0;
}
*/
