/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:37:38 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:49:39 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *) s;
	while (i < n)
	{
		m[i] = c;
		i++;
	}
	return ((void *) m);
}
/*
#include <stdio.h>

int main()
{
	char str[50] = "Hello, World!";
	printf("Before memset: %s\n", str);
	ft_memset(str + 7, '.', 5);
	printf("After memset: %s\n", str);
	return 0;
}
*/
