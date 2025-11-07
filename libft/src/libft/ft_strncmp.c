/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstrncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:32:04 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 20:32:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	if (i == n)
		return (0);
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}
/*
#include <stdio.h>

int main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hello";
	char str3[] = "Hellp";
	char str4[] = "Hell";
	size_t n = 5;

	printf("Comparing '%s' and '%s' with n = %zu: %d\n",
		str1, str2, n, ft_strncmp(str1, str2, n));
	printf("Comparing '%s' and '%s' with n = %zu: %d\n",
		str1, str3, n, ft_strncmp(str1, str3, n));
	printf("Comparing '%s' and '%s' with n = %zu: %d\n",
		str1, str4, n, ft_strncmp(str1, str4, n));
	printf("Comparing '%s' and '%s' with n = %zu: %d\n",
		str4, str1, n, ft_strncmp(str4, str1, n));

	return 0;
}
*/
