/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:39:02 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 11:38:02 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int nb)
{
	long	nbr;
	size_t	c;

	nbr = nb;
	c = 0;
	if (nbr < 0)
		nbr = nbr * (-1);
	if (nbr >= 10)
		c = nbr_len(nbr / 10);
	c++;
	return (c);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	long	nbr;
	char	*cn;

	nbr = n;
	len = nbr_len(n);
	if (n < 0)
		len += 1;
	i = len;
	cn = malloc (len + 1);
	if (!cn)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	while (i--)
	{
		cn[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		cn[0] = '-';
	cn[len] = '\0';
	return (cn);
}

// #include <limits.h>

// int main(void)
// {
// 	int test_values[] = {INT_MAX, INT_MIN, 0, 12345, -12345, 42, -42};
// 	size_t num_tests = sizeof(test_values) / sizeof(test_values[0]);
// 	char *result;

// 	for (size_t i = 0; i < num_tests; i++)
// 	{
// 		result = ft_itoa(test_values[i]);
// 		if (result)
// 		{
// 			printf("ft_itoa(%d) = %s\n", test_values[i], result);
// 			free(result); // Libérer la mémoire allouée par ft_itoa
// 		}
// 		else
// 		{
// 			printf("ft_itoa(%d) failed to allocate memory\n", test_values[i]);
// 		}
// 	}

// 	return 0;
// }
