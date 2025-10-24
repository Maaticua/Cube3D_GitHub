/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:45:56 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:52:59 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!little[i])
		return ((char *) big);
	while (big[i] && i < len)
	{
		n = 0;
		while ((big[i + n] == little[n]) && little[n] && i + n < len)
			n++;
		if (little[n] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include "libft.h"

int main(void)
{
	const char *big = "Hello, world!";
	const char *little = "world";
	size_t len = 12;
	char *result;

	result = ft_strnstr(big, little, len);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");

	return 0;
}
*/
