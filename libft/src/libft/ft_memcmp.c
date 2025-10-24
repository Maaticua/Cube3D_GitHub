/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:23:29 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:49:03 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;
	size_t				i;

	cs1 = (const unsigned char *) s1;
	cs2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
/*

int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcdeg";
	size_t n = 6;

	int result = ft_memcmp(str1, str2, n);
	printf("ft_memcmp result: %d\n", result);

	// Using the standard memcmp for comparison
	int std_result = memcmp(str1, str2, n);
	printf("memcmp result: %d\n", std_result);

	return 0;
}
*/
