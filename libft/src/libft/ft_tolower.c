/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:11:07 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 17:11:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>

int main(void)
{
	char test1 = 'A';
	char test2 = 'Z';
	char test3 = 'a';
	char test4 = 'z';
	char test5 = '1';

	printf("%c -> %c\n", test1, ft_tolower(test1));
	printf("%c -> %c\n", test2, ft_tolower(test2));
	printf("%c -> %c\n", test3, ft_tolower(test3));
	printf("%c -> %c\n", test4, ft_tolower(test4));
	printf("%c -> %c\n", test5, ft_tolower(test5));

	return 0;
}
*/
