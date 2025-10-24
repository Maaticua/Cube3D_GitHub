/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:52:03 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 16:52:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		return (c - 32);
	else
		return (c);
}
/*
int main(void)
{
	char test1 = 'a';
	char test2 = 'z';
	char test3 = 'A';
	char test4 = 'Z';
	char test5 = '1';

	printf("%c -> %c\n", test1, ft_toupper(test1));
	printf("%c -> %c\n", test2, ft_toupper(test2));
	printf("%c -> %c\n", test3, ft_toupper(test3));
	printf("%c -> %c\n", test4, ft_toupper(test4));
	printf("%c -> %c\n", test5, ft_toupper(test5));

	return 0;
}
*/
