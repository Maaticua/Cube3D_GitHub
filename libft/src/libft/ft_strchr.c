/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:23 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:50:56 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
	const char str[] = "Hello, world!";
	char ch = 'o';
	char *result;

	result = ft_strchr(str, ch);
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", ch, result - str);
	else
		printf("Character '%c' not found\n", ch);

	return 0;
}
*/
