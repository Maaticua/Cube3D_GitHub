/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:42 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:52:23 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (i - 1);
}
/*
#include <stdio.h>

int main(void)
{
	const char *str = "Hello, world!";
	printf("Length of '%s' is %zu\n", str, ft_strlen(str));
	return 0;
}
*/
