/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:46:17 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:49:27 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d == 0 && s == 0)
		return (NULL);
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
		return (ft_memcpy(dest, src, n));
	return ((void *) d);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char dest[50] = "Hello, World!";
	const char src[50] = "Goodbye, World!";

	printf("Before memmove: %s\n", dest);
	ft_memmove(dest, src, 7);
	printf("After memmove: %s\n", dest);

	return 0;
}
*/
