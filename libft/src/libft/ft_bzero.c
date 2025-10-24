/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:43:55 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:46:06 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *) s;
	while (i < n)
	{
		m[i] = '\0';
		i++;
	}
}

// int main()
// {
// 	char str[50] = "Hello, World!";
// 	printf("Before ft_bzero: %s\n", str);
// 	ft_bzero(str, 6);
// 	printf("After ft_bzero: %s\n", str);
// 	return 0;
// }
