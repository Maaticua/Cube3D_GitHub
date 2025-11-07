/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:20:34 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:48:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	else
		return (0);
}
/*

int main(void)
{
	char test_chars[] = {'A', ' ', '\n', '1', '~', 127};
	int i;

	for (i = 0; i < 6; i++)
	{
		if (ft_isprint(test_chars[i]))
			printf("Character '%c' is printable.\n", test_chars[i]);
		else
			printf("Character '%c' is not printable.\n", test_chars[i]);
	}
	return 0;
}
*/
