/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:29:51 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:46:36 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

// int	main(void)
// {
// 	int	*arr;
// 	size_t	nmemb = 5;
// 	size_t	size = sizeof(int);
// 	size_t	i;

// 	arr = (int *)ft_calloc(nmemb, size);
// 	if (!arr)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	for (i = 0; i < nmemb; i++)
// 		printf("arr[%zu] = %d\n", i, arr[i]);
// 	free(arr);
// 	return (0);
// }
