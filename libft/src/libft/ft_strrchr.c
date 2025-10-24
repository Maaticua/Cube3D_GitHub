/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:54:51 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 17:54:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
	if (s[i] == (unsigned char) c)
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

	result = ft_strrchr(str, ch);
	if (result != NULL)
		printf("The last occurrence of '%c' in \"%s\"
			is at position: %ld\n", ch, str, result - str);
	else
		printf("Character '%c' not found in \"%s\"\n", ch, str);

	return 0;
}
*/
